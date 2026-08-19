#JustUser

**Fast and lightweight OSINT tool**

![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg?style=for-the-badge&logo=c%2B%2B)
![Size](https://img.shields.io/badge/Binary%20Size-~473%20KB-brightgreen.svg?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Linux-orange.svg?style=for-the-badge&logo=linux)
![License](https://img.shields.io/badge/License-MIT-red.svg?style=for-the-badge)

*Search for user names in different sites about 45+ it is likely fast to other tools because it is written in c++*

##JustUser Features

*Its lightweight and the file size is 475kb*
*No depencieses need for this tool*
*Its likely fast compared to other tools because its written in c++*
*You can scan sites as much as you want.you can do this by editing sites.json file*
*You must include sites like this*
*"GitHub": "https://github.com/",*
*And then save the .json file and have fun with it*

#You Can Download Here

You can run the pre-compiled binary directly without compiling:

```bash
# Clone the repository
git clone [https://github.com/kullanici_adin/JustUser.git](https://github.com/yemxpc/JustUser.git)
cd JustUser

# Run executable
./bin/justuser <target_username>

# Install dependencies

sudo apt update
sudo apt install build-essential cmake libcurl4-openssl-dev

# Build project
mkdir -p build && cd build
cmake ..
make

# Run
cp ../sites.json .
./justuser <target_username>