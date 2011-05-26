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
  return
end

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

print(('-'):rep(80))
print('Creating src/include/config.h')

-- read the original
local config_h_old = ''
do
  local f, err = io.open('../src/include/config.h', 'rt')
  if (f) then
    config_h_old = f:read('*a')
    f:close()
  end
end

-- generate the new text from the sourceFile and a header
local ref = assert(io.open(sourceFile))
local config_h_new = ref:read('*a')
ref:close()
config_h_new = '\n'
            .. '/* Generated by premake4_config/config_h.lua */\n'
            .. '\n'
            .. config_h_new
            .. '\n'

-- write the file, as required
if (config_h_new ~= config_h_old) then
  local f = assert(io.open('../src/include/config.h', 'wt'))
  f:write(config_h_new)
  f:close()
else
  print('-  src/include/config.h  is unchanged')
end

print(('-'):rep(80))

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

local config_h = {
  etc_inet_hosts = nil, -- used by ares

  half_rate_audio = nil, -- linux, cygwin, mingw32

  is_bigendian   = nil,
  is_ansi_const  = nil,
  socklen_t_type = nil,
--[[
AC_APPLE_UNIVERSAL_BUILD
BEOS_USE_GL2
BROKEN_DINPUT
HAVE_ATEXIT
HAVE_USLEEP
HAVE_DEFINED_TOLOWER
HAVE_FF_EFFECT_DIRECTIONAL
HAVE_FF_EFFECT_RUMBLE
HAVE_HSTRERROR
HAVE_LIBBIND
HAVE_LIBM
HAVE_LIBSOCKET
HAVE_LIBWINMM
HAVE_LIBWS2_32
HAVE_SCHED_SETAFFINITY
HAVE_PTHREADS
HAVE_SELECT

HAVE_SLEEP
HAVE_SNOOZE

HAVE_STD__COUNT
HAVE_STD__MAX
HAVE_STD__MIN
HAVE_STD__WSTRING

HAVE_USLEEP

HAVE_WAITFORSINGLEOBJECT
HAVE_WGLGETCURRENTCONTEXT
HAVE_X11_EXTENSIONS_XF86VMODE_H

HAVE__STRICMP
HAVE__STRNICMP
HAVE__VSNPRINTF

LIBCURL_FEATURE_ASYNCHDNS
LIBCURL_FEATURE_IDN
LIBCURL_FEATURE_IPV6
LIBCURL_FEATURE_KRB4
LIBCURL_FEATURE_LIBZ
...


--]]
}

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

local function test_math_func(name)
  return os.testcode {
    code = 'void (*dummy)(void) = (void (*)(void))&atan2f; (void)dummy;',
    includes = { '<math.h>' },
    buildoptions = '-lm',
  }
end

CONFIG.have_acosf  = test_math_func('acosf')
CONFIG.have_asinf  = test_math_func('asinf')
CONFIG.have_atan2f = test_math_func('atan2f')
CONFIG.have_atanf  = test_math_func('atanf')
CONFIG.have_ceilf  = test_math_func('ceilf')
CONFIG.have_cosf   = test_math_func('cosf')
CONFIG.have_expf   = test_math_func('expf')
CONFIG.have_fabsf  = test_math_func('fabsf')
CONFIG.have_floorf = test_math_func('floorf')
CONFIG.have_fmodf  = test_math_func('fmodf')
CONFIG.have_hypotf = test_math_func('hypotf')
CONFIG.have_logf   = test_math_func('logf')
CONFIG.have_log10f = test_math_func('log10f')
CONFIG.have_powf   = test_math_func('powf')
CONFIG.have_sinf   = test_math_func('sinf')
CONFIG.have_sqrtf  = test_math_func('sqrtf')
CONFIG.have_tanf   = test_math_func('tanf')

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

CONFIG.have_std__isnan = os.testcode {
  code = 'const int dummy = std::isnan(1.0f); (void)dummy;',
  includes = { '<cmath>' },
  buildoptions = '-lm',
}

CONFIG.have_isnan = os.testcode {
  code = 'const int dummy = isnan(1.0f); (void)dummy;',
  includes = { '<math.h>' },
  buildoptions = '-lm',
}

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

local function test_header(name)
  return os.testcode {
    code = '',
    includes = { name },
    buildoptions = '-E'  -- this is faster, don't need the full build
  }
end

CONFIG.have_cmath   = test_header('<cmath>')
CONFIG.have_cstdio  = test_header('<cstdio>')
CONFIG.have_cstdlib = test_header('<cstdlib>')
CONFIG.have_cstring = test_header('<cstring>')

CONFIG.have_bstring_h     = test_header('<bstring.h>')
CONFIG.have_curses_h      = test_header('<curses.h>')
CONFIG.have_dlfcn_h       = test_header('<dlfcn.h>')
CONFIG.have_dsound_h      = test_header('<dsound.h>')
CONFIG.have_fcntl_h       = test_header('<fcntl.h>')
CONFIG.have_inttypes_h    = test_header('<inttypes.h>')
CONFIG.have_linux_input_h = test_header('<linux/input.h>')
CONFIG.have_memory_h      = test_header('<memory.h>')
CONFIG.have_ncurses_h     = test_header('<ncurses.h>')
CONFIG.have_netdb_h       = test_header('<netdb.h>')
CONFIG.have_process_h     = test_header('<process.h>')
CONFIG.have_regex_h       = test_header('<regex.h>')
CONFIG.have_sched_h       = test_header('<sched.h>')
CONFIG.have_sdl_sdl_h     = test_header('<SDL/SDL.h>')
CONFIG.have_stdint_h      = test_header('<stdint.h>')
CONFIG.have_sys_param_h   = test_header('<sys/param.h>')
CONFIG.have_sys_socket_h  = test_header('<sys/socket.h>')
CONFIG.have_sys_stat_h    = test_header('<sys/stat.h>')
CONFIG.have_sys_types_h   = test_header('<sys/types.h>')
CONFIG.have_unistd_h      = test_header('<unistd.h>')
CONFIG.have_values_h      = test_header('<values.h>')
CONFIG.have_values_h      = test_header('<xcurses.h>')

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------

if (1 > 0) then -- print CONFIG
  local keys = {}
  for k, v in pairs(CONFIG) do -- FIXME
    keys[#keys + 1] = k
  end
  table.sort(keys, function(a, b)
    return tostring(CONFIG[a]) < tostring(CONFIG[b])
  end)
  for _, key in ipairs(keys) do
    print('CONFIG', key, CONFIG[key])
  end
end

--------------------------------------------------------------------------------
--------------------------------------------------------------------------------
