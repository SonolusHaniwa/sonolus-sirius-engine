using namespace std;

FuncNode update() {
    return {
		drawStage(),
		tutorialNavigation.mod(5),
		Switch(tutorialNavigation.get(), {
			{0, NoteTutorial.Run()},
			{1, FlickTutorial.Run()},
			{2, HoldTutorial.Run()},
			{3, ScratchTutorial.Run()},
			{4, JumpScratchTutorial.Run()}
		})	
	};
}

auto update_unused = defineUpdate(update);
