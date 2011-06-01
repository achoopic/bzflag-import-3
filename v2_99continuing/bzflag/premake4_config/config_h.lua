--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

if (_OPTIONS['help']) then
  return
end

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

local sourceFile = nil

if (_ACTION:match('^vs')) then
  sourceFile = 'config_msvc.h'
elseif ((_ACTION == 'gmake') or
        (_ACTION == 'xcode3') or
        (_ACTION == 'codelite') or
        (_ACTION == 'codeblocks')) then
  sourceFile = 'config_ref.h'
end

if (not sourceFile) then
  print('Not generating config.h, unknown build type.')
  return
end

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

print(('-'):rep(80))
print('Creating src/include/config.h')

-- read the original
local config_h_old = io.readfile('../src/include/config.h', 'rt') or ''

-- generate the new text from the sourceFile and a header
local config_h_new = assert(io.readfile(sourceFile))

config_h_new = '\n'
            .. '/* Generated by premake4_config/config_h.lua */\n'
            .. '\n'
            .. config_h_new
            .. '\n'

-- write the file, as required
if (config_h_new ~= config_h_old) then
  assert(io.writefile('../src/include/config.h', config_h_new))
else
  print('-  src/include/config.h  is unchanged')
end

print(('-'):rep(80))

if (_ACTION:match('^vs')) then
  return
end

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

CONFIG.BZ_BUILD_OS = os.outputof('uname -s'):lower():gsub('\n', '')

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

local function test_math_func(name)
  return os.testcode {
    code = 'void (*dummy)(void) = (void (*)(void))&'..name..'; (void)dummy;',
    includes = { '<math.h>' },
    buildoptions = '-lm',
  }
end

CONFIG.HAVE_ACOSF  = test_math_func('acosf')
CONFIG.HAVE_ASINF  = test_math_func('asinf')
CONFIG.HAVE_ATAN2F = test_math_func('atan2f')
CONFIG.HAVE_ATANF  = test_math_func('atanf')
CONFIG.HAVE_CEILF  = test_math_func('ceilf')
CONFIG.HAVE_COSF   = test_math_func('cosf')
CONFIG.HAVE_EXPF   = test_math_func('expf')
CONFIG.HAVE_FABSF  = test_math_func('fabsf')
CONFIG.HAVE_FLOORF = test_math_func('floorf')
CONFIG.HAVE_FMODF  = test_math_func('fmodf')
CONFIG.HAVE_HYPOTF = test_math_func('hypotf')
CONFIG.HAVE_LOGF   = test_math_func('logf')
CONFIG.HAVE_LOG10F = test_math_func('log10f')
CONFIG.HAVE_POWF   = test_math_func('powf')
CONFIG.HAVE_SINF   = test_math_func('sinf')
CONFIG.HAVE_SQRTF  = test_math_func('sqrtf')
CONFIG.HAVE_TANF   = test_math_func('tanf')

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

CONFIG.HAVE_STD__ISNAN = os.testcode {
  code = 'const int dummy = std::isnan(1.0f); (void)dummy;',
  includes = '<cmath>',
  buildoptions = '-lm',
}

CONFIG.HAVE_ISNAN = os.testcode {
  code = 'const int dummy = isnan(1.0f); (void)dummy;',
  includes = '<math.h>',
  buildoptions = '-lm',
}

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

CONFIG.HAVE_STD__MAX = os.testcode {
  code = '(void)std::max(0, 1);',
  includes = '<algorithm>',
}

CONFIG.HAVE_STD__MIN = os.testcode {
  code = '(void)std::min(0, 1);',
  includes = '<algorithm>',
}

CONFIG.HAVE_STD__COUNT = os.testcode {
  code = 'const char a[] = "test"; (void)std::count(a, a+4, \'t\');',
  includes = '<algorithm>',
}

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

CONFIG.HAVE_SELECT = os.testcode {
  code = '(void)&select;',
  includes = {
    '<sys/select.h>',
    '<sys/time.h>',
    '<sys/types.h>',
    '<unistd.h>',
  },
}

CONFIG.HAVE_ATEXIT = os.testcode {
  code = '(void)&atexit;',
  includes = '<stdlib.h>',
}

CONFIG.HAVE_SLEEP = os.testcode {
  code = '(void)&sleep;',
  includes = '<unistd.h>',
}

CONFIG.HAVE_USLEEP = os.testcode {
  code = '(void)&usleep;',
  includes = '<unistd.h>',
}

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

CONFIG.HAVE__STRICMP = os.testcode {
  code = '(void)&stricmp;',
}

CONFIG.HAVE__STRNICMP = os.testcode {
  code = '(void)&strnicmp;',
}

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

CONFIG.HAVE_VSNPRINTF = os.testcode {
  code = '(void)&vsnprintf;',
  includes = '<stdio.h>',
}

CONFIG.HAVE__VSNPRINTF = os.testcode {
  code = '(void)&_vsnprintf;',
  includes = '<stdio.h>',
}

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

CONFIG.HAVE_SCHED_SETAFFINITY = os.testcode {
  code = '(void)&sched_setaffinity;',
  includes = '<sched.h>',
}

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

CONFIG.HAVE_STD__WSTRING = os.testcode {
  code = '(void)std::wstring();',
  includes = '<iostream>',
}


--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

local function test_header(name)
  return os.testcode {
    code = '',
    includes = name,
    buildoptions = '-E'  -- this is faster, don't need the full build
  }
end

CONFIG.HAVE_CMATH   = test_header('<cmath>')
CONFIG.HAVE_CSTDIO  = test_header('<cstdio>')
CONFIG.HAVE_CSTDLIB = test_header('<cstdlib>')
CONFIG.HAVE_CSTRING = test_header('<cstring>')

CONFIG.HAVE_BSTRING_H     = test_header('<bstring.h>')
CONFIG.HAVE_CURSES_H      = test_header('<curses.h>')
CONFIG.HAVE_DLFCN_H       = test_header('<dlfcn.h>')
CONFIG.HAVE_DSOUND_H      = test_header('<dsound.h>')
CONFIG.HAVE_FCNTL_H       = test_header('<fcntl.h>')
CONFIG.HAVE_INTTYPES_H    = test_header('<inttypes.h>')
CONFIG.HAVE_LINUX_INPUT_H = test_header('<linux/input.h>')
CONFIG.HAVE_MEMORY_H      = test_header('<memory.h>')
CONFIG.HAVE_NCURSES_H     = test_header('<ncurses.h>')
CONFIG.HAVE_NETDB_H       = test_header('<netdb.h>')
CONFIG.HAVE_PROCESS_H     = test_header('<process.h>')
CONFIG.HAVE_REGEX_H       = test_header('<regex.h>')
CONFIG.HAVE_SCHED_H       = test_header('<sched.h>')
CONFIG.HAVE_SDL_SDL_H     = test_header('<SDL/SDL.h>')
CONFIG.HAVE_STDINT_H      = test_header('<stdint.h>')
CONFIG.HAVE_STRING_H      = test_header('<string.h>')
CONFIG.HAVE_STRINGS_H     = test_header('<strings.h>')
CONFIG.HAVE_STDLIB_H      = test_header('<stdlib.h>')
CONFIG.HAVE_SYS_PARAM_H   = test_header('<sys/param.h>')
CONFIG.HAVE_SYS_SOCKET_H  = test_header('<sys/socket.h>')
CONFIG.HAVE_SYS_STAT_H    = test_header('<sys/stat.h>')
CONFIG.HAVE_SYS_TYPES_H   = test_header('<sys/types.h>')
CONFIG.HAVE_UNISTD_H      = test_header('<unistd.h>')
CONFIG.HAVE_VALUES_H      = test_header('<values.h>')
CONFIG.HAVE_XCURSES_H     = test_header('<xcurses.h>')

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

local function test_library(lib)
  return os.testcode {
    code = '',
    includes = name,
    buildoptions = '-l'..lib
  }
end

CONFIG.HAVE_LIBBIND   = test_library('bind')
CONFIG.HAVE_LIBM      = test_library('m')
CONFIG.HAVE_LIBSOCKET = test_library('socket')
CONFIG.HAVE_LIBWINMM  = test_library('winmm')
CONFIG.HAVE_LIBWS2_32 = test_library('ws3_32')

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
--
--  FREETYPE
--

if (not CONFIG.BUILD_FREETYPE) then
  local cflags
  cflags = os.outputof('freetype-config --cflags')
  if (not cflags) then
    cflags = os.outputof('pkg-config freetype2 --cflags')
  else
    cflags = '-I/usr/include/freetype2'
  end

  local incdir = cflags:match('-I(%S+)')
  local success = os.testcode {
    code = [[
      FT_Library ftlib;
      (void)FT_Init_FreeType(&ftlib);
    ]],
    includes = {
      '<ft2build.h>',
      'FT_FREETYPE_H',
    },
    libs = 'freetype',
    buildoptions = '`freetype-config --cflags`' -- FIXME
  }

  CONFIG.BUILD_FREETYPE = not success
end

if (CONFIG.BUILD_FREETYPE) then
  local freetype = getpackage('freetype')
  freetype.includedirs = {
    TOPDIR .. '/other_src/freetype/include'
  }
  freetype.links = 'libfreetype' -- the project name
end


--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
--
--  FTGL
--

-- FTGL 2.1.3 and earlier does not have FTCleanup, which BZFlags needs
-- to prevent a crash on exit.  FTCleanup is not public even in 2.2.0,
-- but ftglCreateBitmapFontFromMem() is (and it is new in 2.2.0), so
-- this test relies upon the assumption that the presence of
-- ftglCreateBitmapFontFromMem() implies the presence of FTCleanup.

if (not CONFIG.BUILD_FTGL) then
  local success = os.testcode {
    code = [[
      const unsigned char fake[] = "invalid bitmap font";
      (void)ftglCreateBitmapFont("FIXME");
      //(void)ftglCreateBitmapFontFromMem(fake, sizeof(fake));
    ]],
    includes = { '<FTGL/ftgl.h>' },
    buildoptions = '`freetype-config --cflags` -lftgl' -- FIXME
  }

  CONFIG.BUILD_FTGL = not success
end

if (CONFIG.BUILD_FTGL) then
  local ftgl = getpackage('ftgl')
  ftgl.links = 'libftgl'
  ftgl.includedirs = {
    TOPDIR .. '/other_src/ftgl/src/FTGL',
  }
end

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
--
--  ARES
--

if (not CONFIG.BUILD_ARES) then
  local success = os.testcode {
    code = [[
      ares_channel ac;
      (void)ares_init(&ac);
    ]],
    includes = { '<ares.h>' },
    libs = 'cares',
  }

  CONFIG.BUILD_ARES = not success
end

if (CONFIG.BUILD_ARES) then
  local ares = getpackage('ares')
  ares.links = 'libares'
  ares.includedirs = {
    TOPDIR .. '/other_src/ares/',
  }
end

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
--
--  CURL
--

if (not CONFIG.BUILD_CURL) then
  local success = os.testcode {
    code = [[
      (void)curl_global_init(0);
    ]],
    includes = { '<curl/curl.h>' },
    libs = 'curl',
  }

  CONFIG.BUILD_CURL = not success
end

if (CONFIG.BUILD_CURL) then
  local curl = getpackage('curl')
  curl.links = 'libcurl'
  curl.includedirs = {
    TOPDIR .. '/other_src/curl/include',
  }
end

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
--
--  ZLIB
--

if (not CONFIG.BUILD_ZLIB) then
  local success = os.testcode {
    code = [[
      (void)compressBound(1);
    ]],
    includes = { '<zlib.h>' },
    libs = 'z',
  }

  CONFIG.BUILD_ZLIB = not success
end

if (CONFIG.BUILD_ZLIB) then
  local zlib = getpackage('zlib')
  zlib.links = 'libz'
  zlib.includedirs = {
    TOPDIR .. '/other_src/zlib/',
  }
end

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
--
--  REGEX
--

if (not CONFIG.BUILD_REGEX) then
  local success = os.testcode {
    code = [[
      regex_t re;
      (void)regcomp(&re, ".*", 0);
    ]],
    includes = { '<regex.h>' },
    libs = 'c',
  }

  CONFIG.BUILD_REGEX = not success
end

if (CONFIG.BUILD_REGEX) then
  local regex = getpackage('regex')
  regex.links = 'libregex'
  regex.includedirs = {
    TOPDIR .. '/other_src/regex/',
  }
end

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

if (-1 > 0) then -- print CONFIG  -- FIXME
  local keys = {}
  local maxlen = 0
  for k, v in pairs(CONFIG) do
    keys[#keys + 1] = k
    if (maxlen < #k) then
      maxlen = #k
    end
  end
  table.sort(keys, function(a, b)
    return tostring(a) < tostring(b)
  end)
  for _, key in ipairs(keys) do
    local value = CONFIG[key]
    if (isboolean(value)) then
      value = value and '1  /* true */' or '0  /* false */'
    end
    printf('CONFIG:  %-'..maxlen..'s  %s', key, tostring(value))
  end
end

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

do
  local fi = assert(io.open('config.h.in', 'rt'))
  local lines = {}
  local linenum = 0
  for line in fi:lines() do
    linenum = linenum + 1
    local s, e, macro, comment = line:find('^%#undef%s+(%S+)(.*)$')
    if (macro) then
      local value = CONFIG[macro]
      local valtype = type(value)
      if (valtype == 'nil') then
        print('WARNING:  unhandled config.h.in macro:  ' .. macro)
        line = ('%-48s/* UNHANDLED MACRO */'):format(line, macro)
      elseif (valtype == 'boolean') then
        if (value) then
          line = ('#define %s 1%s'):format(macro, comment)
        else
          line = ('#undef %s%s'):format(macro, comment)
        end
      elseif (valtype == 'string') then
        line = ('#define %s %q%s'):format(macro, value, comment)
      elseif (valtype == 'number') then
        line = ('#define %s (%g)%s'):format(macro, value, comment)
      else
        line = ('#define %s %s%s'):format(macro, value, comment)
      end
    end
    lines[linenum] = line
  end
  fi:close()

  local text = table.concat(lines, '\n')

  io.writefile('config.h', text, 'wt')
end


--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
