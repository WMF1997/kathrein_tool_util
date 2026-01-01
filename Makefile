build_lib: 
	g++ -fPIC -shared -O2 -I include/ src/kathrein_util.cpp -o out/libkathrein_util.so 

build_test_main:
	g++ -fPIC -shared -O2 -I include/ src/kathrein_util.cpp -o out/libkathrein_util.so 
	g++ -O2 -I include/ -L out/ src/main_test.cpp -lkathrein_util -o out/kathrein_util_exec 
