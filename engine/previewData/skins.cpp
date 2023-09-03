using namespace std;

class Sprites {
    public:

    int Stage = 0;
    int Judgeline = 1;
    int NormalNote = 2;
    int CriticalNote = 3;
    int HoldNote = 4;
    int ScratchNote = 5;
    int ScratchArrow = 6;
    int Hold = 7;
    int Scratch = 8;
    int StageBackground = 9;
    int TouchFeedback = 10;
    int TouchTick = 11;
    int TouchScratchTick = 12;
    int SyncLine = 13;
}Sprites;

auto skins = defineSkins<class Sprites>({
    {SkinSpriteName.StageCover, Sprites.Stage},
    {SkinSpriteName.JudgmentLine, Sprites.Judgeline},
    {SkinSpriteName.NoteHeadRed, Sprites.NormalNote},
    {SkinSpriteName.NoteHeadYellow, Sprites.CriticalNote},
    {SkinSpriteName.NoteHeadBlue, Sprites.HoldNote},
    {SkinSpriteName.NoteHeadPurple, Sprites.ScratchNote},
    {SkinSpriteName.DirectionalMarkerPurple, Sprites.ScratchArrow},
    {SkinSpriteName.NoteConnectionBlue, Sprites.Hold},
    {SkinSpriteName.NoteConnectionPurple, Sprites.Scratch},
    {SkinSpriteName.StageBottomBorder, Sprites.StageBackground},
    {SkinSpriteName.StageMiddle, Sprites.TouchFeedback},
    {SkinSpriteName.NoteTickBlue, Sprites.TouchTick},
    {SkinSpriteName.NoteTickPurple, Sprites.TouchScratchTick},
    {SkinSpriteName.Lane, Sprites.SyncLine},
});