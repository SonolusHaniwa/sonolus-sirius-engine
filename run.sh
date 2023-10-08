ARCH="x64"
VERSION=v1.4.6
YELLOW="\e[93m"
RED="\e[91m"
RESET="\e[0m"

# 下载 Sonolus Server C++
echo -e $YELLOW"Downloading Sonolus Server $VERSION for $ARCH..."$RESET
wget https://ghproxy.com/https://github.com/SonolusHaniwa/sonolus-server-cpp/releases/download/$VERSION/sonolus-server-linux-$ARCH-$VERSION.zip -O sonolus-server/sonolus.zip
cd sonolus-server && unzip -n sonolus.zip

echo -e $YELLOW"Syncing data into database..."$RESET
./sonolus serve &
./sonolus buildcpp play ../sirius
./sonolus buildcpp tutorial ../sirius
./sonolus buildcpp preview ../sirius

# 数据导出
echo -e $YELLOW"Exporting database to data.json..."$RESET
./exportor "http://127.0.0.1:8080" data.json
sudo pkill sonolus

echo -e $YELLOW"Sync finished"$RESET
