using namespace std;

class Icons {
    public:

    int hand = 0;
}Icons;

auto icons = defineInstructionIcons<class Icons>({
    {InstructionIconName.Hand, Icons.hand}
});