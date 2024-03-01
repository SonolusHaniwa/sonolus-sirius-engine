using namespace std;

class ClaimManager {
	customClass(claimedInfo) {
		defineVar(var, index, 0);
		defineVar(var, time, 0);
		defineVar(Rect, hitbix, Rect());
		defineVar(Rect, fullHitbox, Rect());
	};
	Map<LevelMemoryId, var, claimedInfo> claimed = Map<LevelMemoryId, var, claimedInfo>(16);

	var claim(var index, var time, Rect hitbox, Rect fullHitbox, function<var(Touch)> checkTouch) {
		Variable<TemporaryMemoryId> bestTouchIndex, claimedIndex, temp_index, temp_time;
		int temp_hitbox = allocateFixedMemory(TemporaryMemoryId, 4), 
			temp_fullHitbox = allocateFixedMemory(TemporaryMemoryId, 4);
		claimedInfo replaced;
		return {
			temp_index.set(index), temp_time.set(time),
			setFixedMemory(TemporaryMemoryId, temp_hitbox, 4, hitbox.serialize()),
			setFixedMemory(TemporaryMemoryId, temp_fullHitbox, 4, fullHitbox.serialize()),
			{ hitbox = Rect().deserialize(getFixedMemory(TemporaryMemoryId, temp_hitbox, 4)), 0 },
			{ fullHitbox = Rect().deserialize(getFixedMemory(TemporaryMemoryId, temp_hitbox, 4)), 0 },
			Block(While(true, Execute({
				bestTouchIndex.set(findBestTouch(temp_index.get(), temp_time.get(), hitbox, fullHitbox, checkTouch)),
				IF (bestTouchIndex.get() == -1) { Break(1, 0) } FI,

				claimedIndex.set(claimed.indexOf(bestTouchIndex.get())),
				IF (claimedIndex.get() == -1) {
					claimed.set(bestTouchIndex.get(), claimedInfo({
						index: temp_index.get(),
						time: temp_time.get(),
						hitbox: hitbox,
						fullHitbox: fullHitbox
					})),
					Break(1, 0)
				} FI,

				{ replaced = claimed.getValById(claimedIndex.get()), 0 },
				temp_index.set(replaced.index),
				temp_time.set(replaced.time),
				setFixedMemory(TemporaryMemoryId, temp_hitbox, 4, replaced.hitbox.serialize()),
				setFixedMemory(TemporaryMemoryId, temp_fullHitbox, 4, replaced.fullHitbox.serialize()),
				claimed.set(bestTouchIndex.get(), claimedInfo({ 
					index: temp_index.get(), 
					time: temp_time.get(), 
					hitbox: hitbox, 
					fullHitbox: fullHitbox
				}))
			})))
		};
	}

	var findBestTouch(var index, var time, Rect hitbox, Rect fullHitbox, function<var(Touch)> checkTouch) {
		var x = (hitbox.l + hitbox.r) / 2, dist;
		Variable<EntityMemory> id, minDis;
		Variable<EntityMemory> claimedIndex;
		claimedInfo claimedStart;
		return Block(Execute({
			id.set(-1), minDis.set(1e9);
			FOR (i, 0, touches.size(), 1) {
				IF (!checkTouch(touches[i])) { CONTINUE } FI,
				IF (!fullHitbox.contain(touches[i].x, touches[i].y)) { CONTINUE } FI,
				
				dist = Abs(touches[i].x - x),
				IF (id != -1 && dist >= minDis) { CONTINUE } FI,
				
				claimedIndex.set(claimed.indexOf(touches[i].id)),
				IF (claimedIndex == -1) {
					id.set(touches[i].id), minDis.set(dist),
					CONTINUE
				} FI,
				
				{ claimedStart = claimed.getValById(claimedIndex), 0 },
				IF (time > claimedStart.time) { CONTINUE } FI,
				IF (time < claimedStart.time) {
					id.set(touches[i].id), minDis.set(dist),
					CONTINUE
				} FI,
				
				IF (claimedStart.hitbox.contain(touches[i])) { CONTINUE } FI,
				IF (!hitbox.contain(touches[i])) { CONTINUE } FI,
				id.set(touches[i].id), minDis.set(dist),
			} DONE,
			Break(1, id.get())	
		}));
	}
}

auto usedTouchIds = Map<LevelMemoryId, FuncNode, FuncNode>(16);
auto isUsed = [](Touch touch){return Execute({usedTouchIds.indexOf(touch.id) != -1});};
auto markAsUsed = [](Touch touch){return Execute({usedTouchIds.set(touch.id, 1)});};
    
class InputManager: public Archetype {
    public:

    string name = "Sirius Input Manager";

    var spawnOrder() { return 1; }
    
    var shouldSpawn() { return EntityInfoArray.get(2) == EntityState.Despawned; }

    var touch() { return usedTouchIds.clear(); }
};	
