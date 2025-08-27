meson setup "build-android"  \
--cross-file ../build-crossfile \
        -Dndk_root=/usr/android-ndk-r27d/    \
     -Dsdk_ver='34'  \
       --force-fallback-for=libdrm  \
       -Dlibdrm:default_library=static  \
       -Dlibdrm:freedreno-kgsl=true    \
     -Dlibdrm:intel=auto    \
     -Dlibdrm:radeon=auto   \
      -Dlibdrm:amdgpu=auto   \
      -Dlibdrm:nouveau=auto     \
    -Dlibdrm:vmwgfx=enabled     \
    -Dlibdrm:omap=enabled      \
   -Dlibdrm:freedreno=enabled      \
   -Dlibdrm:tegra=enabled    \
     -Dlibdrm:etnaviv=enabled     \
    -Dlibdrm:exynos=enabled    \
     -Dlibdrm:vc4=enabled  \
       -Dminigbm:default_library=static  \

	ninja -C "build-android" install

