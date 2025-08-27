# --- TRUNK 1 START: Project Setup and Header Dependency ---

project('gralloc_gbm_mesa', ['c', 'cpp'],
  version: '1.0',
  default_options: ['cpp_std=c++20']
)

cpu_map = {
  'arm':     'arch-arm-armv7-a-neon',
  'aarch64': 'arch-arm64-armv8-a',
  'x86':     'arch-x86',
  'x86_64':  'arch-x86_64'
}

cpu_family = host_machine.cpu_family()

# Cosmetic rename for display (optional)
cpu_name = (cpu_family == 'aarch64') ? 'arm64' : cpu_family

inst_name = cpu_map.get(cpu_family, '')

message('CPU name: ' + cpu_name)
message('Instruction dir: ' + inst_name)

ndk_root = get_option('ndk_root')
if ndk_root == ''
  ndk_root = meson.get_external_property('ndk_root', '')
endif

if ndk_root == ''
  error('You must set ndk_root either in the cross file or with -Dndk_root=...')
endif

# Usually mapper5 stable-c only available for v34
sdk_ver = meson.get_external_property('sdk_ver', '')
message('sdk_ver: ' + sdk_ver)

if sdk_ver == ''
  sdk_ver = meson.get_external_property('SDK_VER', '')
  message('sdk_ver: ' + sdk_ver)
endif

if sdk_ver == ''
  sdk_ver = get_option('sdk_ver')
  message('sdk_ver: ' + sdk_ver)
endif

if sdk_ver == ''
  sdk_ver = get_option('SDK_VER')
  message('sdk_ver: ' + sdk_ver)
endif

if sdk_ver == ''
    error('You must set SDK_VER/sdk_ver either in the cross file or with -Dsdk_ver=... OR -Dsdk_VER=...')
endif

vndk_sp = join_paths(ndk_root,'prebuilt/vndk/', 'v' + sdk_ver, cpu_name, inst_name,'shared/vndk-sp/')
message('vndk_sp: ' + vndk_sp)

vndk_llndk_stub = join_paths(ndk_root,'prebuilt/vndk/', 'v' + sdk_ver, cpu_name, inst_name,'shared/llndk-stub/')
vndk_core = join_paths(ndk_root,'prebuilt/vndk/', 'v' + sdk_ver, cpu_name, inst_name,'shared/vndk-core/')

# Extended include paths for Android VNDK v34
# Each path below has a comment describing what headers it provides
inc_extra_v34 = include_directories(
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/libbase/include/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/core/libsystem/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/core/libcutils/include'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/hardware/libhardware/include/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/core/libsystem/include/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/core/libsync/include'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/core/libvndksupport/include'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/core/libsysutils/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/hardware/interfaces/graphics/common/aidl/android.hardware.graphics.common-V4-ndk-source/gen/include/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/core/libcutils/include'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/logging/liblog/include_vndk/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/hardware/interfaces/graphics/allocator/aidl/android.hardware.graphics.allocator-V2-ndk-source/gen/include/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/hardware/interfaces/graphics/common/1.2/android.hardware.graphics.common@1.2_genc++_headers/gen/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/hardware/interfaces/graphics/common/1.1/android.hardware.graphics.common@1.1_genc++_headers/gen/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/hardware/interfaces/graphics/common/1.0/android.hardware.graphics.common@1.0_genc++_headers/gen/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/libhidl/base/include/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/core/libutils/include'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/libfmq/base/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/hardware/interfaces/graphics/mapper/4.0/android.hardware.graphics.mapper@4.0_genc++_headers/gen/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/system/libhidl/transport/base/1.0/android.hidl.base@1.0_genc++_headers/gen/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/system/libhidl/transport/manager/1.0/android.hidl.manager@1.0_genc++_headers/gen/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/frameworks/native/libs/gralloc/types/include/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/frameworks/native/libs/nativewindow/include/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/frameworks/native/libs/nativebase/include/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/hardware/interfaces/common/aidl/android.hardware.common-V2-ndk-source/gen/include/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/frameworks/native/libs/binder/ndk/include_platform/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/hardware/interfaces/graphics/allocator/4.0/android.hardware.graphics.allocator@4.0_genc++_headers/gen/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/hardware/interfaces/graphics/common/aidl/android.hardware.graphics.common-V4-ndk-source/gen/include/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/libhidl/transport/include/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/libhwbinder/include/'),
  join_paths('.', 'include/stable-c-v34/include'),
  join_paths('.', 'include/stable-c-v34/implutils/include/'),
  join_paths('.', 'include/')
)

cc = meson.get_compiler('c')

minigbm_proj = subproject('minigbm')
gbm_dep = minigbm_proj.get_variable('gbm_deps')

gralloc_gm_headers = declare_dependency(
  include_directories: include_directories('src/include')
)

# --- TRUNK 1 END ---
# --- TRUNK 2 START: Shared Library libgralloc_gm ---
# All your HIDL lib names in one place
hidl_libs = [
'libbase',
'libbinder_ndk',
'libcutils',
'libdmabufheap',
'libdrm',
'libgbm_mesa',
'libgralloctypes',
'libhidlbase',
'liblog',
'libnativewindow',
'libsync',
]

# Collect deps, skipping missing ones
common_hidl_deps = []
foreach name : hidl_libs
  dep = cc.find_library(name, required: false, dirs: [vndk_llndk_stub, vndk_sp, vndk_core])
  if dep.found()
    common_hidl_deps += dep
    message('lib found:' + name)
  else
    message('lib not found:' + name)
  endif
endforeach

common_hidl_exec_deps = []


libgralloc_gm = shared_library('gralloc.gm',
  sources: [
	'src/gralloc_gbm_mesa.cpp',
        'src/aidl/Allocator.cpp',
        'src/aidl/IAllocator.cpp',
        'src/aidl/BufferDescriptorInfo.cpp',
        'src/aidl/NativeHandle.cpp',
        'src/aidl/ExtendableType.cpp',
        'src/aidl/AllocationResult.cpp',
        'src/aidl/NativeHandle.cpp',
        'src/aidl/aidlcommonsupport/NativeHandle.cpp',
        'src/aidl/AllocationResult.cpp',
  ],
  include_directories: [
	include_directories('src/include'),
	inc_extra_v34,
  ],
  dependencies: [
	common_hidl_deps,
  ],
  link_whole: [
	gbm_dep,
  ],
  cpp_args: [
    '-D_GNU_SOURCE=1',
    '-D_FILE_OFFSET_BITS=64',
    '-Wall',
    '-Wsign-compare',
    '-Wpointer-arith',
    '-Wcast-qual',
    '-Wcast-align',
    '-Wno-unused-parameter'
  ],
  name_prefix : '',
  install: true
)

libgralloc_gm_deps = declare_dependency(
  link_with : libgralloc_gm,
#  include_directories : inc_minigbm
)

# --- TRUNK 2 END ---
# --- TRUNK 3 START: Gralloc HAL Module gralloc.gm ---

gralloc_gm_module = executable('android.hardware.graphics.allocator-service.gm',
  sources: [
        'src/aidl/Main.cpp',
  ],
  include_directories: [
	include_directories('src/include'),
        inc_extra_v34,
  ],  
  dependencies: [
    libgralloc_gm_deps,
    common_hidl_deps,
  ],
  cpp_args: [
  ],
  install: true
)

# --- TRUNK 3 END ---
# --- TRUNK 4 START: Gralloc GM Test Suite ---
if false
gralloc_gm_tests = executable('gralloc_gm_tests',
  sources: [
    'tests/test_gralloc_gbm.cpp',
  ],
  include_directories: include_directories([
    'src/include',
    'tests/include',
  ]),
  dependencies: [
    libgralloc_gm,
    common_hidl_deps,
  ],
  cpp_args: [
    '-D_GNU_SOURCE=1',
    '-D_FILE_OFFSET_BITS=64',
    '-Wall',
    '-Wextra',
    '-Wno-unused-parameter'
  ],
  install: false
)

test('gralloc_gm_tests', gralloc_gm_tests)
endif
# --- TRUNK 4 END ---
# --- TRUNK 5 START: Installation and Packaging ---

install_data('src/aidl/android.hardware.graphics.allocator-service.gm.rc',
  install_dir: join_paths(get_option('sysconfdir'), 'gralloc_gm')
)

install_headers('src/include/gralloc_gbm_mesa.h',
  subdir: 'gralloc_gm'
)

#meson.add_install_script('scripts/post_install.sh')

# --- TRUNK 5 END ---
