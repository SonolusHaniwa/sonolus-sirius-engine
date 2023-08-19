# Sonolus Sirius Engine

A recreation of World Dai Star: Dream's Stellarium engine in [Sonolus](https://sonolus.com). For Sonolus 0.7.x.

适用于 Sonolus 0.7.2+ 的 World Dai Star: Dream's Stellarium 引擎。

Use [sonolus.h](https://github.com/SonolusHaniwa/sonolus.h) and [sonolus-server-cpp](https://github.com/SonolusHaniwa/sonolus-server-cpp) to develop.

Todo List:



使用 Sonolus Server C++ v1.4.5 进行开发，并在 Ubuntu amd64 环境下编译通过。

## Links

- [Sonolus Website](https://sonolus.com) 
- [Sonolus Wiki](https://github.com/NonSpicyBurrito/sonolus-wiki)
- [sonolus.h](https://github.com/SonolusHaniwa/sonolus.h)

## Installation

```bash
sudo apt install libjsoncpp-dev openssl zlib1g-dev libssl-dev -y # 安装环境依赖
git clone https://github.com/SonolusHaniwa/sonolus-sirius-engine # 拉取源码
cd sonolus-sirius-engine # 修改目录
g++ main.cpp -o main -ljsoncpp -lssl -lcrypto -lz -Dplay # 编译程序
./main # 在 dist 文件夹下生成 EnginePlayData 和 EngineConfiguration
g++ main.cpp -o main -ljsoncpp -lssl -lcrypto -lz -Dtutorial # 编译程序
./main # 在 dist 文件夹下生成 EngineTutorialData 和 EngineConfiguration
./main LevelData.txt dist/LevelData # 在 dist 文件夹下生成 LevelData
```

## Custom Resources

### Skin Sprites

|ID|Sprite| 
|:-:|:-:|
|0|Sirius Stage|
|1|Sirius Judgeline|
|2|Sirius Normal Note|
|3|Sirius Critical Note|
|4|Sirius Hold Note|
|5|Sirius Scratch Note|
|6|Sirius Scratch Arrow|
|7|Sirius Hold|
|8|Sirius Scratch|
|9|Sirius Stage Background

### Effect Clips

|ID|Clip|
|:-:|:-:|
|0|Sirius Miss|
|1|Sirius Great|
|2|Sirius Flick Great|
|3|Sirius Perfect|
|4|Sirius Flick Perfect|
|5|Sirius Hold Start|
|6|Sirius Scratch|
|7|Sirius Hold|

### Particle Effects

|ID|Effect|
|:-:|:-:|
|||