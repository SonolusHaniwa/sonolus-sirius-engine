class Stage: public Archetype {
    public:

    string name = "Sirius Stage";
    bool input = false;

    var spawnOrder = 2;

    var shouldSpawn = 1;

    var drawJudgeline() {
        return Draw(Sprites.Judgeline, judgline.lbX, judgline.lbY, judgline.ltX, judgline.ltY, judgline.rtX, judgline.rtY, judgline.rbX, judgline.rbY, 3, 1);
    }

    var updateSequential = {
        Draw(Sprites.Stage, stage.l, stage.b, stage.l * highWidth, stage.t, stage.r * highWidth, stage.t, stage.r, stage.b, 1, 1),
        Draw(Sprites.StageBackground, stage.l, stage.b, stage.l * highWidth, stage.t, stage.r * highWidth, stage.t, stage.r, stage.b, 2, 0.6),
        drawJudgeline()
    }; 

    var touch = {

    };
};