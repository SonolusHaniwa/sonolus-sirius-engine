using namespace std;

FuncNode updateSpawn() {
	return { times.now };
}

auto updateSpawn_unused = defineUpdateSpawn(updateSpawn);
