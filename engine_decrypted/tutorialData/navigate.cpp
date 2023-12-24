using namespace std;

FuncNode navigate() {
	return {
		IF (navigation.direction > 0) {
			tutorialNavigation.add(1)
		} ELSE {
			tutorialNavigation.subtract(1)
		} FI,
		tutorialStartTime.set(times.now),
		instruction.set(-1)	
	};
}

auto navigate_unused = defineNavigate(navigate);
