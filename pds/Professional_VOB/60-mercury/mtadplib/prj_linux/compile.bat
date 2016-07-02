#!/bin/sh
	
make -f makefile_82xx_d clean

make -f makefile_82xx_d 1> ../../../10-common/version/compileinfo/mtadp_linux_ppc_82xx_d.txt
cp ./libmtadp.a ../../../10-common/lib/debug/linux_ppc_82xx/

echo makefile_82xx_d completed!


make -f makefile_82xx_r clean

make -f makefile_82xx_r 1> ../../../10-common/version/compileinfo/mtadp_linux_ppc_82xx_r.txt
cp ./libmtadp.a ../../../10-common/lib/release/linux_ppc_82xx/

echo makefile_82xx_r completed!

make -f makefile_82xx_mpc_embedded_d clean

make -f makefile_82xx_mpc_embedded_d 1> ../../../10-common/version/compileinfo/mtadp_linux_ppc_82xx_d.txt
cp ./libmtadpembedded.a ../../../10-common/lib/debug/linux_ppc_82xx/

echo makefile_82xx_mpc_embedded_d completed!

make -f makefile_82xx_mpc_embedded_r clean

make -f makefile_82xx_mpc_embedded_r 1> ../../../10-common/version/compileinfo/mtadp_linux_ppc_82xx_r.txt
cp ./libmtadpembedded.a ../../../10-common/lib/release/linux_ppc_82xx/

echo makefile_82xx_mpc_embedded_r completed!


make -f makefile_85xx_d clean

make -f makefile_85xx_d 1> ../../../10-common/version/compileinfo/mtadp_linux_ppc_85xx_d.txt
cp ./libmtadp.a ../../../10-common/lib/debug/linux_ppc_85xx/

echo makefile_85xx_d completed!


make -f makefile_85xx_r clean

make -f makefile_85xx_r 1> ../../../10-common/version/compileinfo/mtadp_linux_ppc_85xx_r.txt
cp ./libmtadp.a ../../../10-common/lib/release/linux_ppc_85xx/

echo makefile_85xx_r completed!

make -f makefile_85xx_mpc_embedded_d clean

make -f makefile_85xx_mpc_embedded_d 1> ../../../10-common/version/compileinfo/mtadp_linux_ppc_85xx_d.txt
cp ./libmtadpembedded.a ../../../10-common/lib/debug/linux_ppc_85xx/

echo makefile_85xx_mpc_embedded_d completed!


make -f makefile_85xx_mpc_embedded_r clean

make -f makefile_85xx_mpc_embedded_r 1> ../../../10-common/version/compileinfo/mtadp_linux_ppc_85xx_r.txt
cp ./libmtadpembedded.a ../../../10-common/lib/release/linux_ppc_85xx/

echo makefile_85xx_mpc_embedded_r completed!


make -f makefile_rh_d clean

make -f makefile_rh_d 1> ../../../10-common/version/compileinfo/mtadp_linux_g++_rh_d.txt
cp ./libmtadp8ke.a ../../../10-common/lib/debug/linux/

echo makefile_rh_d completed!


make -f makefile_rh_r clean

make -f makefile_rh_r 1> ../../../10-common/version/compileinfo/mtadp_linux_g++_rh_r.txt
cp ./libmtadp8ke.a ../../../10-common/lib/release/linux/

echo makefile_rh_r completed!



make -f makefile_rh8000h_d clean

make -f makefile_rh8000h_d 1> ../../../10-common/version/compileinfo/mtadp_linux_g++_rh8000h_d.txt
cp ./libmtadp8kh.a ../../../10-common/lib/debug/linux/8khlib/

echo makefile_rh8000h_d completed!


make -f makefile_rh8000h_r clean

make -f makefile_rh8000h_r 1> ../../../10-common/version/compileinfo/mtadp_linux_g++_rh8000h_r.txt
cp ./libmtadp8kh.a ../../../10-common/lib/release/linux/8khlib/

echo makefile_rh8000h_r completed!



make -f makefile_rh8000i_d clean

make -f makefile_rh8000i_d 1> ../../../10-common/version/compileinfo/mtadp_linux_g++_rh8000i_d.txt
cp ./libmtadp8ki.a ../../../10-common/lib/debug/linux/8kilib/

echo makefile_rh8000i_d completed!

make -f makefile_rh8000i_r clean

make -f makefile_rh8000i_r 1> ../../../10-common/version/compileinfo/mtadp_linux_g++_rh8000i_r.txt
cp ./libmtadp8ki.a ../../../10-common/lib/release/linux/8kilib/

echo makefile_rh8000i_r completed!


make -f makefile_82xxhdi_d clean

make -f makefile_82xxhdi_d 1> ../../../10-common/version/compileinfo/mtadp_linux_ppc_82xx_hdi_d.txt
cp ./libmtadphdi.a ../../../10-common/lib/debug/linux_ppc_82xx/

echo makefile_82xxhdi_d completed!


make -f makefile_82xxhdi_r clean

make -f makefile_82xxhdi_r 1> ../../../10-common/version/compileinfo/mtadp_linux_ppc_82xx_hdi_r.txt
cp ./libmtadphdi.a ../../../10-common/lib/release/linux_ppc_82xx/

echo makefile_82xxhdi_r completed!

make -f makefile_85xxhdi_d clean

make -f makefile_85xxhdi_d 1> ../../../10-common/version/compileinfo/mtadp_linux_ppc_85xx_hdi_d.txt
cp ./libmtadphdi.a ../../../10-common/lib/debug/linux_ppc_85xx/

echo makefile_85xxhdi_d completed!


make -f makefile_85xxhdi_r clean

make -f makefile_85xxhdi_r 1> ../../../10-common/version/compileinfo/mtadp_linux_ppc_85xx_hdi_r.txt
cp ./libmtadphdi.a ../../../10-common/lib/release/linux_ppc_85xx/

echo makefile_85xxhdi_r completed!


make -f makefile_rhhdi_d clean

make -f makefile_rhhdi_d 1> ../../../10-common/version/compileinfo/mtadp_linux_g++_rh_8000b_d.txt
cp ./libmtadphdi.a ../../../10-common/lib/debug/linux/

echo makefile_rhhdi_d completed!


make -f makefile_rhhdi_r clean

make -f makefile_rhhdi_r 1> ../../../10-common/version/compileinfo/mtadp_linux_g++_rh_8000b_r.txt
cp ./libmtadphdi.a ../../../10-common/lib/release/linux/

echo makefile_rhhdi_r completed!


make -f makefile_82xx_linux12_d clean

make -f makefile_82xx_linux12_d 1> ../../../10-common/version/compileinfo/mtadp_82xx_linux12_d.txt
cp ./libmtadp12.a ../../../10-common/lib/debug/linux_ppc_82xx/

echo makefile_82xx_linux12_d completed!


make -f makefile_82xx_linux12_r clean

make -f makefile_82xx_linux12_r 1> ../../../10-common/version/compileinfo/mtadp_82xx_linux12_r.txt
cp ./libmtadp12.a ../../../10-common/lib/release/linux_ppc_82xx/

echo makefile_82xx_linux12_r completed!


make -f makefile_82xx_mpc_embedded_linux12_d clean

make -f makefile_82xx_mpc_embedded_linux12_d 1> ../../../10-common/version/compileinfo/mtadp_82xx_linux12_d.txt
cp ./libmtadp12embedded.a ../../../10-common/lib/debug/linux_ppc_82xx/

echo makefile_82xx_mpc_embedded_linux12_d completed!


make -f makefile_82xx_mpc_embedded_linux12_r clean

make -f makefile_82xx_mpc_embedded_linux12_r 1> ../../../10-common/version/compileinfo/mtadp_82xx_linux12_r.txt
cp ./libmtadp12embedded.a ../../../10-common/lib/release/linux_ppc_82xx/

echo makefile_82xx_mpc_embedded_linux12_r completed!


make -f makefile_85xx_linux12_d clean

make -f makefile_85xx_linux12_d 1> ../../../10-common/version/compileinfo/mtadp_linux12_ppc_85xx_d.txt
cp ./libmtadp12.a ../../../10-common/lib/debug/linux_ppc_85xx/

echo makefile_85xx_linux12_d completed!


make -f makefile_85xx_linux12_r clean

make -f makefile_85xx_linux12_r 1> ../../../10-common/version/compileinfo/mtadp_linux12_ppc_85xx_r.txt
cp ./libmtadp12.a ../../../10-common/lib/release/linux_ppc_85xx/

echo makefile_85xx_linux12_r completed!


make -f makefile_85xxhdi_linux12_r clean
make -f makefile_85xxhdi_linux12_r 1> ../../../10-common/version/compileinfo/mtadp_linux_ppc_85xx_hdi_linux12_r.txt
cp ./libmtadphdi12.a ../../../10-common/lib/release/linux_ppc_85xx/

echo makefile_85xxhdi_linux12_r completed!


make -f makefile_85xxhdi_linux12_d clean
make -f makefile_85xxhdi_linux12_d 1> ../../../10-common/version/compileinfo/mtadp_linux_ppc_85xx_hdi_linux12_d.txt
cp ./libmtadphdi12.a ../../../10-common/lib/debug/linux_ppc_85xx/

echo makefile_85xxhdi_linux12_d completed!


make -f makefile_82xxhdi_linux12_r clean
make -f makefile_82xxhdi_linux12_r 1> ../../../10-common/version/compileinfo/mtadp_linux_ppc_82xx_hdi_linux12_r.txt
cp ./libmtadphdi12.a ../../../10-common/lib/release/linux_ppc_82xx/

echo makefile_82xxhdi_linux12_r completed!

make -f makefile_82xxhdi_linux12_d clean
make -f makefile_82xxhdi_linux12_d 1> ../../../10-common/version/compileinfo/mtadp_linux_ppc_82xx_hdi_linux12_d.txt
cp ./libmtadphdi12.a ../../../10-common/lib/debug/linux_ppc_82xx/

echo makefile_82xxhdi_linux12_d completed!

cd ..
