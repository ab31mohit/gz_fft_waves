# gz_fft_waves
- This gz package simulates realistic ocean waves generated using FFT.   
- This is a modification of the original work done by [srmainwaring](https://github.com/srmainwaring).  
- The goal is to simplify the code base for using only fft based waves and improve realistic reflections.  

    ![](media/ocean_waves.gif)

## Dependencies  
- A working installatin of gazebo sim (harmonic/garden/ionic)
- This package uses [FFTW](https://www.fftw.org/) and [CGAL](https://www.cgal.org/), both of which are GPL-3.0 Licensed.

- Ubuntu-22.04 (Jammy)

## Installing dependencies :  
- Install gazebo harmonic from [here](https://gazebosim.org/docs/harmonic/install_ubuntu/).  

- Install Colcon for building the package  

    ```bash
    sudo apt install python3-pip
    pip install -U colcon-common-extensions
    ```  
- Install fftw/[intel-mkl](https://www.intel.com/content/www/us/en/developer/tools/oneapi/onemkl-download.html?operatingsystem=linux&linux-install=apt) (for fft) and cgal (for geometric computations) libraries

    ```bash
    sudo apt-get update
    sudo apt-get install libcgal-dev libfftw3-dev
    sudo apt install -y gpg-agent wget
    wget -O- https://apt.repos.intel.com/intel-gpg-keys/GPG-PUB-KEY-INTEL-SW-PRODUCTS.PUB | gpg --dearmor | sudo tee /usr/share/keyrings/oneapi-archive-keyring.gpg > /dev/null
    echo "deb [signed-by=/usr/share/keyrings/oneapi-archive-keyring.gpg] https://apt.repos.intel.com/oneapi all main" | sudo tee /etc/apt/sources.list.d/oneAPI.list
    sudo apt update
    sudo apt install intel-oneapi-mkl
    sudo apt install intel-oneapi-mkl-devel
    ```   

    - run this onetime command to source the oneapi mkl 

        ```bash
        source /opt/intel/oneapi/setvars.sh
        ```


## Setting up this project  

- Create a workspace and clone this repo

    ```bash
    mkdir -p ~/gz_waves_ws/src
    cd ~/gz_waves_ws/src
    git clone https://github.com/ab31mohit/gz_fft_waves.git
    ```  

- Copy and paste the following lines of code in `.bashrc` file  

    ```bash
    export GZ_VERSION=harmonic
    export GZ_IP=127.0.0.1
    export GZ_DISCOVERY_MULTICST=0

    # waves setup
    source ~/gz_waves_ws/install/setup.bash

    export GZ_SIM_RESOURCE_PATH=\
    $GZ_SIM_RESOURCE_PATH:\
    ~/gz_waves_ws/src/gz_fft_waves/models:\
    ~/gz_waves_ws/src/gz_fft_waves/worlds

    export GZ_SIM_SYSTEM_PLUGIN_PATH=\
    $GZ_SIM_SYSTEM_PLUGIN_PATH:\
    ~/workspace~/gz_waves_ws/install/lib
    ``` 

- Build the package   

    ```bash
    cd ~/gz_waves_ws/
    colcon build --symlink-install --merge-install --cmake-args \
    -DCMAKE_BUILD_TYPE=RelWithDebInfo \
    -DBUILD_TESTING=ON \
    -DCMAKE_CXX_STANDARD=17
    source ~/.bashrc
    ```  
    In case yout system gets stuck during the build process again and again, you can use  

    ```bash
    cd ~/gz_waves_ws/
    rm -rf build/ install/ log/
    LDFLAGS="-Wl,--no-keep-memory" MAKEFLAGS="-j1" colcon build \
    --executor sequential \
    --parallel-workers 1 \
    --cmake-args \  
    -DBUILD_TESTING=OFF \  
    -DCMAKE_BUILD_TYPE=RelWithDebInfo \
    -DCMAKE_INTERPROCEDURAL_OPTIMIZATION=OFF
    source ~/.bashrc
    ``` 

- The simply run the ***ocean.sdf*** world file directly from the terminal  

    ```bash
    gz sim -v4 ocean.sdf
    ```  

- By default the current code uses Intel MKL oneapi for fft computation.  
- For using FFTW3, just interchange the code between these 2 set of files 

    [LinearRandomFFTWaveSimulationImpl.hh](include/gz_fft_waves/core/LinearRandomFFTWaveSimulationImpl.hh)  <-----> [LinearRandomFFTWaveSimulationImpl_backup.hh](include/gz_fft_waves/core/LinearRandomFFTWaveSimulationImpl_backup.hh)  

    [LinearRandomFFTWaveSimulation.cc](src/core/LinearRandomFFTWaveSimulation.cc)   <-----> [LinearRandomFFTWaveSimulation_backup.cc](src/core/LinearRandomFFTWaveSimulation_backup.cc)

- the backup files contain fft computation code using fftw3 library and the current version contains fft computation code using intel mkl oneapi.  

