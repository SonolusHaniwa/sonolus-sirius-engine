# Sonolus Sirius Engine

A recreation of World Dai Star: Dream's Stellarium engine in [Sonolus](https://sonolus.com). For Sonolus 0.8.0.

适用于 Sonolus 0.8.0 的 World Dai Star: Dream's Stellarium 引擎。

Use [sonolus.h](https://github.com/SonolusHaniwa/sonolus.h) and [sonolus-server-cpp](https://github.com/SonolusHaniwa/sonolus-server-cpp) to develop.

Todo List:

- [x] Finish writing buckets system
- [x] Finish writing tutorial mode
- [x] Finish writing preview mode
- [x] Finish writing watch mode
- [x] Designed particle effect for sirius
- [x] Update to Sonolus v0.7.4
- [x] Update to Sonolus v0.8.0

## Preview

### Play Mode

![Play Mode Perfect](./1.jpg)

![Play Mode Full Combo](./2.jpg)

### Preview Mode

![Preview Mode](./4.jpg)

### Watch Mode

![Watch Mode](./3.jpg)

### Replay Mode

![Replay Mode](./5.jpg)

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
g++ main.cpp -o main -ljsoncpp -lssl -lcrypto -lz -Dpreview # 编译程序
./main # 在 dist 文件夹下生成 EnginePreviewData 和 EngineConfiguration
g++ main.cpp -o main -ljsoncpp -lssl -lcrypto -lz -Dwatch # 编译程序
./main # 在 dist 文件夹下生成 EngineWatchData 和 EngineConfiguration
./main txt2data LevelData.txt music_config.txt dist/LevelData # 在 dist 文件夹下生成 LevelData
```

## JavaScript Convertor Module

**You need install [emscripten](https://github.com/emscripten-core/emscripten) first.**

Compile Command:

```bash
sudo chmod 0777 ./emake && ./emake
```

It will create `libsirius.js` and `libsirius.wasm`. Here's a simple code for your reference:

```javascript
import factory from './libsirius.js';

async function fromSUS(sus) {
	var inst = await factory();
	var ptr = inst.stringToNewUTF8(sus); // 将字符串转为 char* 指针
	// char* _sus2txt(char*): 将 sus 转为 txt 文件
	// char* _txt2data(char*): 将 txt 转为未加密的 LevelData
	var res = inst._txt2data(inst._sus2txt(ptr));
	var dat = inst.UTF8ToString(res); // 从 char* 转回为字符串
	return dat;
}

var txt = fromSUS(sus); // 将 sus 转为 LevelData(未加密)
```

## Documentation

### `char* sus2txt(char* sus)` / `string fromSUS(string text)`

Convert sus chart to wds txt chart.

- `sus` / `text`: Chart content.

### `char* txt2data(char* txt)` / `string fromSirius(string text, double chartOffset, double bgmOffset = 0)`

Convert wds txt chart to Sonolus LevelData (without gzip encoded).

- `txt` / `text`: Chart content.
- `chartOffset`: Chart offset.
- `bgmOffset`: BGM offset (or delay seconds in music_config.txt).

## Custom Resources

### Custom Chart(English)

Please use Ched to write WDS Chart. Here's nite transformation table:

|Sirius|Ched|
|:-:|:-:|
|Tap Note|Tap Note|
|Critical Note|Critical Note|
|Flick Note|Flick Note + Swing up Air|
|Hold Note(Blue)|Slide Note|
|Scratch Hold Note(Purple)|Swing Air at the end of the Slide|
|Critical (Scratch) Hold Note|Critical Note at the start of the Slide|
|(Scratch) Hold Note without Start Note|Damage Note at the start of the Slide|
|Scratch Note(the one above the Hold)|Swing Air in the middle of the Slide|
|(Scratch) Hold Relay Point|Slide Relay Point|
|Jump Scratch Note|Flick to overlap the start and end points of the Scratch Hold you want to connect|
|Split Line|Use the HiSpeed event to specify, with integer parts specifying the number of tracks and decimal parts specifying the split line style. If the integer part is a multiple of ten, it indicates the end of the split line.|

Sample Chatt: [chs format](https://oneindex.littleyang.me/api/raw?path=/data/satellite.chs) [sus format](https://oneindex.littleyang.me/api/raw?path=/data/satellite.sus) [chart preview video](https://www.bilibili.com/video/BV1AH4y1R7xX)

### 自制谱方法(简体中文)

请使用 Ched 编写世界大明星谱面，下列是音符对照表:

|Sirius|Ched|
|:-:|:-:|
|Tap 音符|Tap 音符|
|高亮 Tap 音符|高亮 Tap 音符|
|Flick 音符|Flick 音符 + 向上 Air 音符|
|Hold 音符(青色)|Slide 音符|
|Scratch Hold 音符(紫色)|Slide 终点 + 向上 Air 音符|
|高亮 (Scratch) Hold 音符|Slide 起点 + 高亮 Tap 音符|
|无头 (Scratch) Hold 音符|Slide 起点 + Damage 音符|
|Scratch 音符(在 Hold 音符中)|Slide 中途 + 向上 Air 音符|
|(Scratch) Hold 中继点|Hold 中继点|
|Jump Scratch 音符|用 Flick 音符覆盖一个 Slide 音符的起点和另一个 Slide 音符的重点 + 指定方向的 Air 音符|
|分裂线|使用 HiSpeed 事件指定，整数部分指定轨道数，小数部分指定分裂线样式。整数部分为整十数表示分裂线结束|

样例谱面: [chs 格式](https://oneindex.littleyang.me/api/raw?path=/data/satellite.chs) [sus 格式](https://oneindex.littleyang.me/api/raw?path=/data/satellite.sus) [谱面预览视频](https://www.bilibili.com/video/BV1AH4y1R7xX)
