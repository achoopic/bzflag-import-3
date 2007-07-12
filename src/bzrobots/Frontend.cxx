#include "Frontend.h"

#include "TimeKeeper.h"
#include "RCMessageFactory.h"
#include "TestRobot.h"
#include "ScriptLoaderFactory.h"

#include "bzsignal.h"

#include <iostream>
#include <unistd.h>

bool Frontend::run(std::string filename, const char *host, int port)
{
  pid_t pid = fork();
  if (pid < 0)
    return false;
  else if (pid > 0)
    return true;

  fclose(stdin); // Shouldn't mess around with that here ;-)
  bzSignal(SIGINT, SIG_DFL);

  Frontend frontend;
  if (!frontend.connect(host, port))
  {
    std::cerr << "Frontend failed to connect! Bailing! (" << frontend.getError() << ")" << std::endl;
    return false;
  }

  std::cout << "Frontend initialized, " << host << ":" << port << std::endl;
  frontend.start(filename);
  std::cerr << "Frontend disconnected / failed! (" << frontend.getError() << ")" << std::endl;
  return false;
}

Frontend::Frontend() :sentStuff(false)
{
  RCMessageFactory<RCReply>::initialize();
}
bool Frontend::connect(const char *host, int port)
{
  link = new RCLinkFrontend();
  RCREPLY.setLink(link);
  return link->connect(host, port);
}

void Frontend::start(std::string filename)
{
  std::string::size_type extension_pos = filename.find_last_of(".");
  if (extension_pos == std::string::npos || extension_pos >= filename.length())
  {
    error = "Could not find a valid extension in filename '" + filename + "'.";
    return;
  }
  std::string extension = filename.substr(extension_pos + 1);

  if (!SCRIPTLOADER.IsRegistered(extension))
  {
    error = "Could not find a proper ScriptLoader for extension '" + extension + "'.";
    return;
  }

  scriptLoader = SCRIPTLOADER.scriptLoader(extension);
  if (!scriptLoader->load(filename))
  {
    error = "Could not load script: " + scriptLoader->getError();
    return;
  }

  robot = scriptLoader->create();
  if (robot == NULL)
  {
    error = "Could not instantiate robot via ScriptLoader for file '" + filename + "'.";
    return;
  }

  while (link->getStatus() != RCLink::Connected)
  {
    link->update();
    TimeKeeper::sleep(0.5);
  }

  robot->setLink(link);
  robot->run();

  error = "Bot finished executing, shouldn't really happen.";
}

// Local Variables: ***
// mode:C++ ***
// tab-width: 8 ***
// c-basic-offset: 2 ***
// indent-tabs-mode: t ***
// End: ***
// ex: shiftwidth=2 tabstop=8

