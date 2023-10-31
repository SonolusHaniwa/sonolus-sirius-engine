using namespace std;

auto update = defineUpdate({
    drawStage(),
	tutorialNavigation.mod(5),
	Switch(tutorialNavigation.get(), {
		{0, NoteTutorial.Run()},
		{1, FlickTutorial.Run()}
	})
});
