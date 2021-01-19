#!/bin/bash
cat > .internal_script <<EOF
#!/bin/bash
cd $(pwd)
mkdir -p build
cd build
scan-build cmake .. -G "Unix Makefiles"
scan-build make
make install
cd ..
./bin/tests
EOF
chmod +x .internal_script

docker run -it --rm \
    -v $(pwd):$(pwd) \
    -v /etc/timezone:/etc/timezone \
    -v /etc/localtime:/etc/localtime \
    -u $(id -u):$(id -g) \
    mickare/cmake-clang bash $(pwd)/.internal_script

rm .internal_script
