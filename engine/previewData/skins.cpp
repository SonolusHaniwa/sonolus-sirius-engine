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
    int SplitLine_1 = 14;
    int SplitLineTrans1_1 = 15;
    int SplitLineTrans2_1 = 16;
    int SplitLine_10010 = 17;
    int SplitLineTrans1_10010 = 18;
    int SplitLineTrans2_10010 = 19;
    int SplitLine_10020 = 20;
    int SplitLineTrans1_10020 = 21;
    int SplitLineTrans2_10020 = 22;
    int SplitLine_10030 = 23;
    int SplitLineTrans1_10030 = 24;
    int SplitLineTrans2_10030 = 25;
    int SplitLine_10040 = 26;
    int SplitLineTrans1_10040 = 27;
    int SplitLineTrans2_10040 = 28;
    int SplitLine_10050 = 29;
    int SplitLineTrans1_10050 = 30;
    int SplitLineTrans2_10050 = 31;
    int SplitLine_10060 = 32;
    int SplitLineTrans1_10060 = 33;
    int SplitLineTrans2_10060 = 34;
    int SplitLine_10070 = 35;
    int SplitLineTrans1_10070 = 36;
    int SplitLineTrans2_10070 = 37;
    int SplitLine_1010 = 38;
    int SplitLineTrans1_1010 = 39;
    int SplitLineTrans2_1010 = 40;
    int SplitLine_10100 = 41;
    int SplitLineTrans1_10100 = 42;
    int SplitLineTrans2_10100 = 43;
    int SplitLine_10110 = 44;
    int SplitLineTrans1_10110 = 45;
    int SplitLineTrans2_10110 = 46;
    int SplitLine_10120 = 47;
    int SplitLineTrans1_10120 = 48;
    int SplitLineTrans2_10120 = 49;
    int SplitLine_10130 = 50;
    int SplitLineTrans1_10130 = 51;
    int SplitLineTrans2_10130 = 52;
    int SplitLine_10140 = 53;
    int SplitLineTrans1_10140 = 54;
    int SplitLineTrans2_10140 = 55;
    int SplitLine_10150 = 56;
    int SplitLineTrans1_10150 = 57;
    int SplitLineTrans2_10150 = 58;
    int SplitLine_10160 = 59;
    int SplitLineTrans1_10160 = 60;
    int SplitLineTrans2_10160 = 61;
    int SplitLine_10161 = 62;
    int SplitLineTrans1_10161 = 63;
    int SplitLineTrans2_10161 = 64;
    int SplitLine_10162 = 65;
    int SplitLineTrans1_10162 = 66;
    int SplitLineTrans2_10162 = 67;
    int SplitLine_10170 = 68;
    int SplitLineTrans1_10170 = 69;
    int SplitLineTrans2_10170 = 70;
    int SplitLine_10180 = 71;
    int SplitLineTrans1_10180 = 72;
    int SplitLineTrans2_10180 = 73;
    int SplitLine_10190 = 74;
    int SplitLineTrans1_10190 = 75;
    int SplitLineTrans2_10190 = 76;
    int SplitLine_10191 = 77;
    int SplitLineTrans1_10191 = 78;
    int SplitLineTrans2_10191 = 79;
    int SplitLine_1020 = 80;
    int SplitLineTrans1_1020 = 81;
    int SplitLineTrans2_1020 = 82;
    int SplitLine_10200 = 83;
    int SplitLineTrans1_10200 = 84;
    int SplitLineTrans2_10200 = 85;
    int SplitLine_10220 = 86;
    int SplitLineTrans1_10220 = 87;
    int SplitLineTrans2_10220 = 88;
    int SplitLine_10230 = 89;
    int SplitLineTrans1_10230 = 90;
    int SplitLineTrans2_10230 = 91;
    int SplitLine_10240 = 92;
    int SplitLineTrans1_10240 = 93;
    int SplitLineTrans2_10240 = 94;
    int SplitLine_10250 = 95;
    int SplitLineTrans1_10250 = 96;
    int SplitLineTrans2_10250 = 97;
    int SplitLine_10260 = 98;
    int SplitLineTrans1_10260 = 99;
    int SplitLineTrans2_10260 = 100;
    int SplitLine_1030 = 101;
    int SplitLineTrans1_1030 = 102;
    int SplitLineTrans2_1030 = 103;
    int SplitLine_10320 = 104;
    int SplitLineTrans1_10320 = 105;
    int SplitLineTrans2_10320 = 106;
    int SplitLine_10321_1 = 107;
    int SplitLineTrans1_10321_1 = 108;
    int SplitLineTrans2_10321_1 = 109;
    int SplitLine_10321_2 = 110;
    int SplitLineTrans1_10321_2 = 111;
    int SplitLineTrans2_10321_2 = 112;
    int SplitLine_10321_3 = 113;
    int SplitLineTrans1_10321_3 = 114;
    int SplitLineTrans2_10321_3 = 115;
    int SplitLine_10321_4 = 116;
    int SplitLineTrans1_10321_4 = 117;
    int SplitLineTrans2_10321_4 = 118;
    int SplitLine_10321_5 = 119;
    int SplitLineTrans1_10321_5 = 120;
    int SplitLineTrans2_10321_5 = 121;
    int SplitLine_10322_1 = 122;
    int SplitLineTrans1_10322_1 = 123;
    int SplitLineTrans2_10322_1 = 124;
    int SplitLine_10322_2 = 125;
    int SplitLineTrans1_10322_2 = 126;
    int SplitLineTrans2_10322_2 = 127;
    int SplitLine_10322_3 = 128;
    int SplitLineTrans1_10322_3 = 129;
    int SplitLineTrans2_10322_3 = 130;
    int SplitLine_10322_4 = 131;
    int SplitLineTrans1_10322_4 = 132;
    int SplitLineTrans2_10322_4 = 133;
    int SplitLine_10322_5 = 134;
    int SplitLineTrans1_10322_5 = 135;
    int SplitLineTrans2_10322_5 = 136;
    int SplitLine_10323_1 = 137;
    int SplitLineTrans1_10323_1 = 138;
    int SplitLineTrans2_10323_1 = 139;
    int SplitLine_10323_2 = 140;
    int SplitLineTrans1_10323_2 = 141;
    int SplitLineTrans2_10323_2 = 142;
    int SplitLine_10323_3 = 143;
    int SplitLineTrans1_10323_3 = 144;
    int SplitLineTrans2_10323_3 = 145;
    int SplitLine_10323_4 = 146;
    int SplitLineTrans1_10323_4 = 147;
    int SplitLineTrans2_10323_4 = 148;
    int SplitLine_10323_5 = 149;
    int SplitLineTrans1_10323_5 = 150;
    int SplitLineTrans2_10323_5 = 151;
    int SplitLine_10324_1 = 152;
    int SplitLineTrans1_10324_1 = 153;
    int SplitLineTrans2_10324_1 = 154;
    int SplitLine_10324_2 = 155;
    int SplitLineTrans1_10324_2 = 156;
    int SplitLineTrans2_10324_2 = 157;
    int SplitLine_10324_3 = 158;
    int SplitLineTrans1_10324_3 = 159;
    int SplitLineTrans2_10324_3 = 160;
    int SplitLine_10325_1 = 161;
    int SplitLineTrans1_10325_1 = 162;
    int SplitLineTrans2_10325_1 = 163;
    int SplitLine_10325_2 = 164;
    int SplitLineTrans1_10325_2 = 165;
    int SplitLineTrans2_10325_2 = 166;
    int SplitLine_10325_3 = 167;
    int SplitLineTrans1_10325_3 = 168;
    int SplitLineTrans2_10325_3 = 169;
    int SplitLine_10325_4 = 170;
    int SplitLineTrans1_10325_4 = 171;
    int SplitLineTrans2_10325_4 = 172;
    int SplitLine_10326_1 = 173;
    int SplitLineTrans1_10326_1 = 174;
    int SplitLineTrans2_10326_1 = 175;
    int SplitLine_10326_2 = 176;
    int SplitLineTrans1_10326_2 = 177;
    int SplitLineTrans2_10326_2 = 178;
    int SplitLine_10326_3 = 179;
    int SplitLineTrans1_10326_3 = 180;
    int SplitLineTrans2_10326_3 = 181;
    int SplitLine_10326_4 = 182;
    int SplitLineTrans1_10326_4 = 183;
    int SplitLineTrans2_10326_4 = 184;
    int SplitLine_10326_5 = 185;
    int SplitLineTrans1_10326_5 = 186;
    int SplitLineTrans2_10326_5 = 187;
    int SplitLine_10327_1 = 188;
    int SplitLineTrans1_10327_1 = 189;
    int SplitLineTrans2_10327_1 = 190;
    int SplitLine_10327_2 = 191;
    int SplitLineTrans1_10327_2 = 192;
    int SplitLineTrans2_10327_2 = 193;
    int SplitLine_10327_3 = 194;
    int SplitLineTrans1_10327_3 = 195;
    int SplitLineTrans2_10327_3 = 196;
    int SplitLine_10327_4 = 197;
    int SplitLineTrans1_10327_4 = 198;
    int SplitLineTrans2_10327_4 = 199;
    int SplitLine_10328_1 = 200;
    int SplitLineTrans1_10328_1 = 201;
    int SplitLineTrans2_10328_1 = 202;
    int SplitLine_10328_2 = 203;
    int SplitLineTrans1_10328_2 = 204;
    int SplitLineTrans2_10328_2 = 205;
    int SplitLine_10328_3 = 206;
    int SplitLineTrans1_10328_3 = 207;
    int SplitLineTrans2_10328_3 = 208;
    int SplitLine_10328_4 = 209;
    int SplitLineTrans1_10328_4 = 210;
    int SplitLineTrans2_10328_4 = 211;
    int SplitLine_10328_5 = 212;
    int SplitLineTrans1_10328_5 = 213;
    int SplitLineTrans2_10328_5 = 214;
    int SplitLine_10340 = 215;
    int SplitLineTrans1_10340 = 216;
    int SplitLineTrans2_10340 = 217;
    int SplitLine_10350 = 218;
    int SplitLineTrans1_10350 = 219;
    int SplitLineTrans2_10350 = 220;
    int SplitLine_10360 = 221;
    int SplitLineTrans1_10360 = 222;
    int SplitLineTrans2_10360 = 223;
    int SplitLine_10361 = 224;
    int SplitLineTrans1_10361 = 225;
    int SplitLineTrans2_10361 = 226;
    int SplitLine_10390 = 227;
    int SplitLineTrans1_10390 = 228;
    int SplitLineTrans2_10390 = 229;
    int SplitLine_10391 = 230;
    int SplitLineTrans1_10391 = 231;
    int SplitLineTrans2_10391 = 232;
    int SplitLine_10392 = 233;
    int SplitLineTrans1_10392 = 234;
    int SplitLineTrans2_10392 = 235;
    int SplitLine_10393 = 236;
    int SplitLineTrans1_10393 = 237;
    int SplitLineTrans2_10393 = 238;
    int SplitLine_1040 = 239;
    int SplitLineTrans1_1040 = 240;
    int SplitLineTrans2_1040 = 241;
    int SplitLine_1050 = 242;
    int SplitLineTrans1_1050 = 243;
    int SplitLineTrans2_1050 = 244;
    int SplitLine_1060a = 245;
    int SplitLineTrans1_1060a = 246;
    int SplitLineTrans2_1060a = 247;
    int SplitLine_1060b = 248;
    int SplitLineTrans1_1060b = 249;
    int SplitLineTrans2_1060b = 250;
    int SplitLine_2 = 251;
    int SplitLineTrans1_2 = 252;
    int SplitLineTrans2_2 = 253;
    int SplitLine_2010 = 254;
    int SplitLineTrans1_2010 = 255;
    int SplitLineTrans2_2010 = 256;
    int SplitLine_2020 = 257;
    int SplitLineTrans1_2020 = 258;
    int SplitLineTrans2_2020 = 259;
    int SplitLine_2030 = 260;
    int SplitLineTrans1_2030 = 261;
    int SplitLineTrans2_2030 = 262;
    int SplitLine_2040a = 263;
    int SplitLineTrans1_2040a = 264;
    int SplitLineTrans2_2040a = 265;
    int SplitLine_2040b = 266;
    int SplitLineTrans1_2040b = 267;
    int SplitLineTrans2_2040b = 268;
    int SplitLine_2050 = 269;
    int SplitLineTrans1_2050 = 270;
    int SplitLineTrans2_2050 = 271;
    int SplitLine_3 = 272;
    int SplitLineTrans1_3 = 273;
    int SplitLineTrans2_3 = 274;
    int SplitLine_3010 = 275;
    int SplitLineTrans1_3010 = 276;
    int SplitLineTrans2_3010 = 277;
    int SplitLine_3020 = 278;
    int SplitLineTrans1_3020 = 279;
    int SplitLineTrans2_3020 = 280;
    int SplitLine_3030 = 281;
    int SplitLineTrans1_3030 = 282;
    int SplitLineTrans2_3030 = 283;
    int SplitLine_3040 = 284;
    int SplitLineTrans1_3040 = 285;
    int SplitLineTrans2_3040 = 286;
    int SplitLine_3050 = 287;
    int SplitLineTrans1_3050 = 288;
    int SplitLineTrans2_3050 = 289;
    int SplitLine_4 = 290;
    int SplitLineTrans1_4 = 291;
    int SplitLineTrans2_4 = 292;
    int SplitLine_4010 = 293;
    int SplitLineTrans1_4010 = 294;
    int SplitLineTrans2_4010 = 295;
    int SplitLine_4020 = 296;
    int SplitLineTrans1_4020 = 297;
    int SplitLineTrans2_4020 = 298;
    int SplitLine_4030 = 299;
    int SplitLineTrans1_4030 = 300;
    int SplitLineTrans2_4030 = 301;
    int SplitLine_4040 = 302;
    int SplitLineTrans1_4040 = 303;
    int SplitLineTrans2_4040 = 304;
    int SplitLine_4050 = 305;
    int SplitLineTrans1_4050 = 306;
    int SplitLineTrans2_4050 = 307;
    int SplitLine_5 = 308;
    int SplitLineTrans1_5 = 309;
    int SplitLineTrans2_5 = 310;
    int SplitLine_6 = 311;
    int SplitLineTrans1_6 = 312;
    int SplitLineTrans2_6 = 313;
    int SplitLine_7 = 314;
    int SplitLineTrans1_7 = 315;
    int SplitLineTrans2_7 = 316;
    int SplitLine_8 = 317;
    int SplitLineTrans1_8 = 318;
    int SplitLineTrans2_8 = 319;
    int SplitLine_9 = 320;
    int SplitLineTrans1_9 = 321;
    int SplitLineTrans2_9 = 322;
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
    {"Sirius Split Line #1", Sprites.SplitLine_1},
    {"Sirius Split Line Transform 1 #1", Sprites.SplitLineTrans1_1},
    {"Sirius Split Line Transform 2 #1", Sprites.SplitLineTrans2_1},
    {"Sirius Split Line #10010", Sprites.SplitLine_10010},
    {"Sirius Split Line Transform 1 #10010", Sprites.SplitLineTrans1_10010},
    {"Sirius Split Line Transform 2 #10010", Sprites.SplitLineTrans2_10010},
    {"Sirius Split Line #10020", Sprites.SplitLine_10020},
    {"Sirius Split Line Transform 1 #10020", Sprites.SplitLineTrans1_10020},
    {"Sirius Split Line Transform 2 #10020", Sprites.SplitLineTrans2_10020},
    {"Sirius Split Line #10030", Sprites.SplitLine_10030},
    {"Sirius Split Line Transform 1 #10030", Sprites.SplitLineTrans1_10030},
    {"Sirius Split Line Transform 2 #10030", Sprites.SplitLineTrans2_10030},
    {"Sirius Split Line #10040", Sprites.SplitLine_10040},
    {"Sirius Split Line Transform 1 #10040", Sprites.SplitLineTrans1_10040},
    {"Sirius Split Line Transform 2 #10040", Sprites.SplitLineTrans2_10040},
    {"Sirius Split Line #10050", Sprites.SplitLine_10050},
    {"Sirius Split Line Transform 1 #10050", Sprites.SplitLineTrans1_10050},
    {"Sirius Split Line Transform 2 #10050", Sprites.SplitLineTrans2_10050},
    {"Sirius Split Line #10060", Sprites.SplitLine_10060},
    {"Sirius Split Line Transform 1 #10060", Sprites.SplitLineTrans1_10060},
    {"Sirius Split Line Transform 2 #10060", Sprites.SplitLineTrans2_10060},
    {"Sirius Split Line #10070", Sprites.SplitLine_10070},
    {"Sirius Split Line Transform 1 #10070", Sprites.SplitLineTrans1_10070},
    {"Sirius Split Line Transform 2 #10070", Sprites.SplitLineTrans2_10070},
    {"Sirius Split Line #1010", Sprites.SplitLine_1010},
    {"Sirius Split Line Transform 1 #1010", Sprites.SplitLineTrans1_1010},
    {"Sirius Split Line Transform 2 #1010", Sprites.SplitLineTrans2_1010},
    {"Sirius Split Line #10100", Sprites.SplitLine_10100},
    {"Sirius Split Line Transform 1 #10100", Sprites.SplitLineTrans1_10100},
    {"Sirius Split Line Transform 2 #10100", Sprites.SplitLineTrans2_10100},
    {"Sirius Split Line #10110", Sprites.SplitLine_10110},
    {"Sirius Split Line Transform 1 #10110", Sprites.SplitLineTrans1_10110},
    {"Sirius Split Line Transform 2 #10110", Sprites.SplitLineTrans2_10110},
    {"Sirius Split Line #10120", Sprites.SplitLine_10120},
    {"Sirius Split Line Transform 1 #10120", Sprites.SplitLineTrans1_10120},
    {"Sirius Split Line Transform 2 #10120", Sprites.SplitLineTrans2_10120},
    {"Sirius Split Line #10130", Sprites.SplitLine_10130},
    {"Sirius Split Line Transform 1 #10130", Sprites.SplitLineTrans1_10130},
    {"Sirius Split Line Transform 2 #10130", Sprites.SplitLineTrans2_10130},
    {"Sirius Split Line #10140", Sprites.SplitLine_10140},
    {"Sirius Split Line Transform 1 #10140", Sprites.SplitLineTrans1_10140},
    {"Sirius Split Line Transform 2 #10140", Sprites.SplitLineTrans2_10140},
    {"Sirius Split Line #10150", Sprites.SplitLine_10150},
    {"Sirius Split Line Transform 1 #10150", Sprites.SplitLineTrans1_10150},
    {"Sirius Split Line Transform 2 #10150", Sprites.SplitLineTrans2_10150},
    {"Sirius Split Line #10160", Sprites.SplitLine_10160},
    {"Sirius Split Line Transform 1 #10160", Sprites.SplitLineTrans1_10160},
    {"Sirius Split Line Transform 2 #10160", Sprites.SplitLineTrans2_10160},
    {"Sirius Split Line #10161", Sprites.SplitLine_10161},
    {"Sirius Split Line Transform 1 #10161", Sprites.SplitLineTrans1_10161},
    {"Sirius Split Line Transform 2 #10161", Sprites.SplitLineTrans2_10161},
    {"Sirius Split Line #10162", Sprites.SplitLine_10162},
    {"Sirius Split Line Transform 1 #10162", Sprites.SplitLineTrans1_10162},
    {"Sirius Split Line Transform 2 #10162", Sprites.SplitLineTrans2_10162},
    {"Sirius Split Line #10170", Sprites.SplitLine_10170},
    {"Sirius Split Line Transform 1 #10170", Sprites.SplitLineTrans1_10170},
    {"Sirius Split Line Transform 2 #10170", Sprites.SplitLineTrans2_10170},
    {"Sirius Split Line #10180", Sprites.SplitLine_10180},
    {"Sirius Split Line Transform 1 #10180", Sprites.SplitLineTrans1_10180},
    {"Sirius Split Line Transform 2 #10180", Sprites.SplitLineTrans2_10180},
    {"Sirius Split Line #10190", Sprites.SplitLine_10190},
    {"Sirius Split Line Transform 1 #10190", Sprites.SplitLineTrans1_10190},
    {"Sirius Split Line Transform 2 #10190", Sprites.SplitLineTrans2_10190},
    {"Sirius Split Line #10191", Sprites.SplitLine_10191},
    {"Sirius Split Line Transform 1 #10191", Sprites.SplitLineTrans1_10191},
    {"Sirius Split Line Transform 2 #10191", Sprites.SplitLineTrans2_10191},
    {"Sirius Split Line #1020", Sprites.SplitLine_1020},
    {"Sirius Split Line Transform 1 #1020", Sprites.SplitLineTrans1_1020},
    {"Sirius Split Line Transform 2 #1020", Sprites.SplitLineTrans2_1020},
    {"Sirius Split Line #10200", Sprites.SplitLine_10200},
    {"Sirius Split Line Transform 1 #10200", Sprites.SplitLineTrans1_10200},
    {"Sirius Split Line Transform 2 #10200", Sprites.SplitLineTrans2_10200},
    {"Sirius Split Line #10220", Sprites.SplitLine_10220},
    {"Sirius Split Line Transform 1 #10220", Sprites.SplitLineTrans1_10220},
    {"Sirius Split Line Transform 2 #10220", Sprites.SplitLineTrans2_10220},
    {"Sirius Split Line #10230", Sprites.SplitLine_10230},
    {"Sirius Split Line Transform 1 #10230", Sprites.SplitLineTrans1_10230},
    {"Sirius Split Line Transform 2 #10230", Sprites.SplitLineTrans2_10230},
    {"Sirius Split Line #10240", Sprites.SplitLine_10240},
    {"Sirius Split Line Transform 1 #10240", Sprites.SplitLineTrans1_10240},
    {"Sirius Split Line Transform 2 #10240", Sprites.SplitLineTrans2_10240},
    {"Sirius Split Line #10250", Sprites.SplitLine_10250},
    {"Sirius Split Line Transform 1 #10250", Sprites.SplitLineTrans1_10250},
    {"Sirius Split Line Transform 2 #10250", Sprites.SplitLineTrans2_10250},
    {"Sirius Split Line #10260", Sprites.SplitLine_10260},
    {"Sirius Split Line Transform 1 #10260", Sprites.SplitLineTrans1_10260},
    {"Sirius Split Line Transform 2 #10260", Sprites.SplitLineTrans2_10260},
    {"Sirius Split Line #1030", Sprites.SplitLine_1030},
    {"Sirius Split Line Transform 1 #1030", Sprites.SplitLineTrans1_1030},
    {"Sirius Split Line Transform 2 #1030", Sprites.SplitLineTrans2_1030},
    {"Sirius Split Line #10320", Sprites.SplitLine_10320},
    {"Sirius Split Line Transform 1 #10320", Sprites.SplitLineTrans1_10320},
    {"Sirius Split Line Transform 2 #10320", Sprites.SplitLineTrans2_10320},
    {"Sirius Split Line #10321_1", Sprites.SplitLine_10321_1},
    {"Sirius Split Line Transform 1 #10321_1", Sprites.SplitLineTrans1_10321_1},
    {"Sirius Split Line Transform 2 #10321_1", Sprites.SplitLineTrans2_10321_1},
    {"Sirius Split Line #10321_2", Sprites.SplitLine_10321_2},
    {"Sirius Split Line Transform 1 #10321_2", Sprites.SplitLineTrans1_10321_2},
    {"Sirius Split Line Transform 2 #10321_2", Sprites.SplitLineTrans2_10321_2},
    {"Sirius Split Line #10321_3", Sprites.SplitLine_10321_3},
    {"Sirius Split Line Transform 1 #10321_3", Sprites.SplitLineTrans1_10321_3},
    {"Sirius Split Line Transform 2 #10321_3", Sprites.SplitLineTrans2_10321_3},
    {"Sirius Split Line #10321_4", Sprites.SplitLine_10321_4},
    {"Sirius Split Line Transform 1 #10321_4", Sprites.SplitLineTrans1_10321_4},
    {"Sirius Split Line Transform 2 #10321_4", Sprites.SplitLineTrans2_10321_4},
    {"Sirius Split Line #10321_5", Sprites.SplitLine_10321_5},
    {"Sirius Split Line Transform 1 #10321_5", Sprites.SplitLineTrans1_10321_5},
    {"Sirius Split Line Transform 2 #10321_5", Sprites.SplitLineTrans2_10321_5},
    {"Sirius Split Line #10322_1", Sprites.SplitLine_10322_1},
    {"Sirius Split Line Transform 1 #10322_1", Sprites.SplitLineTrans1_10322_1},
    {"Sirius Split Line Transform 2 #10322_1", Sprites.SplitLineTrans2_10322_1},
    {"Sirius Split Line #10322_2", Sprites.SplitLine_10322_2},
    {"Sirius Split Line Transform 1 #10322_2", Sprites.SplitLineTrans1_10322_2},
    {"Sirius Split Line Transform 2 #10322_2", Sprites.SplitLineTrans2_10322_2},
    {"Sirius Split Line #10322_3", Sprites.SplitLine_10322_3},
    {"Sirius Split Line Transform 1 #10322_3", Sprites.SplitLineTrans1_10322_3},
    {"Sirius Split Line Transform 2 #10322_3", Sprites.SplitLineTrans2_10322_3},
    {"Sirius Split Line #10322_4", Sprites.SplitLine_10322_4},
    {"Sirius Split Line Transform 1 #10322_4", Sprites.SplitLineTrans1_10322_4},
    {"Sirius Split Line Transform 2 #10322_4", Sprites.SplitLineTrans2_10322_4},
    {"Sirius Split Line #10322_5", Sprites.SplitLine_10322_5},
    {"Sirius Split Line Transform 1 #10322_5", Sprites.SplitLineTrans1_10322_5},
    {"Sirius Split Line Transform 2 #10322_5", Sprites.SplitLineTrans2_10322_5},
    {"Sirius Split Line #10323_1", Sprites.SplitLine_10323_1},
    {"Sirius Split Line Transform 1 #10323_1", Sprites.SplitLineTrans1_10323_1},
    {"Sirius Split Line Transform 2 #10323_1", Sprites.SplitLineTrans2_10323_1},
    {"Sirius Split Line #10323_2", Sprites.SplitLine_10323_2},
    {"Sirius Split Line Transform 1 #10323_2", Sprites.SplitLineTrans1_10323_2},
    {"Sirius Split Line Transform 2 #10323_2", Sprites.SplitLineTrans2_10323_2},
    {"Sirius Split Line #10323_3", Sprites.SplitLine_10323_3},
    {"Sirius Split Line Transform 1 #10323_3", Sprites.SplitLineTrans1_10323_3},
    {"Sirius Split Line Transform 2 #10323_3", Sprites.SplitLineTrans2_10323_3},
    {"Sirius Split Line #10323_4", Sprites.SplitLine_10323_4},
    {"Sirius Split Line Transform 1 #10323_4", Sprites.SplitLineTrans1_10323_4},
    {"Sirius Split Line Transform 2 #10323_4", Sprites.SplitLineTrans2_10323_4},
    {"Sirius Split Line #10323_5", Sprites.SplitLine_10323_5},
    {"Sirius Split Line Transform 1 #10323_5", Sprites.SplitLineTrans1_10323_5},
    {"Sirius Split Line Transform 2 #10323_5", Sprites.SplitLineTrans2_10323_5},
    {"Sirius Split Line #10324_1", Sprites.SplitLine_10324_1},
    {"Sirius Split Line Transform 1 #10324_1", Sprites.SplitLineTrans1_10324_1},
    {"Sirius Split Line Transform 2 #10324_1", Sprites.SplitLineTrans2_10324_1},
    {"Sirius Split Line #10324_2", Sprites.SplitLine_10324_2},
    {"Sirius Split Line Transform 1 #10324_2", Sprites.SplitLineTrans1_10324_2},
    {"Sirius Split Line Transform 2 #10324_2", Sprites.SplitLineTrans2_10324_2},
    {"Sirius Split Line #10324_3", Sprites.SplitLine_10324_3},
    {"Sirius Split Line Transform 1 #10324_3", Sprites.SplitLineTrans1_10324_3},
    {"Sirius Split Line Transform 2 #10324_3", Sprites.SplitLineTrans2_10324_3},
    {"Sirius Split Line #10325_1", Sprites.SplitLine_10325_1},
    {"Sirius Split Line Transform 1 #10325_1", Sprites.SplitLineTrans1_10325_1},
    {"Sirius Split Line Transform 2 #10325_1", Sprites.SplitLineTrans2_10325_1},
    {"Sirius Split Line #10325_2", Sprites.SplitLine_10325_2},
    {"Sirius Split Line Transform 1 #10325_2", Sprites.SplitLineTrans1_10325_2},
    {"Sirius Split Line Transform 2 #10325_2", Sprites.SplitLineTrans2_10325_2},
    {"Sirius Split Line #10325_3", Sprites.SplitLine_10325_3},
    {"Sirius Split Line Transform 1 #10325_3", Sprites.SplitLineTrans1_10325_3},
    {"Sirius Split Line Transform 2 #10325_3", Sprites.SplitLineTrans2_10325_3},
    {"Sirius Split Line #10325_4", Sprites.SplitLine_10325_4},
    {"Sirius Split Line Transform 1 #10325_4", Sprites.SplitLineTrans1_10325_4},
    {"Sirius Split Line Transform 2 #10325_4", Sprites.SplitLineTrans2_10325_4},
    {"Sirius Split Line #10326_1", Sprites.SplitLine_10326_1},
    {"Sirius Split Line Transform 1 #10326_1", Sprites.SplitLineTrans1_10326_1},
    {"Sirius Split Line Transform 2 #10326_1", Sprites.SplitLineTrans2_10326_1},
    {"Sirius Split Line #10326_2", Sprites.SplitLine_10326_2},
    {"Sirius Split Line Transform 1 #10326_2", Sprites.SplitLineTrans1_10326_2},
    {"Sirius Split Line Transform 2 #10326_2", Sprites.SplitLineTrans2_10326_2},
    {"Sirius Split Line #10326_3", Sprites.SplitLine_10326_3},
    {"Sirius Split Line Transform 1 #10326_3", Sprites.SplitLineTrans1_10326_3},
    {"Sirius Split Line Transform 2 #10326_3", Sprites.SplitLineTrans2_10326_3},
    {"Sirius Split Line #10326_4", Sprites.SplitLine_10326_4},
    {"Sirius Split Line Transform 1 #10326_4", Sprites.SplitLineTrans1_10326_4},
    {"Sirius Split Line Transform 2 #10326_4", Sprites.SplitLineTrans2_10326_4},
    {"Sirius Split Line #10326_5", Sprites.SplitLine_10326_5},
    {"Sirius Split Line Transform 1 #10326_5", Sprites.SplitLineTrans1_10326_5},
    {"Sirius Split Line Transform 2 #10326_5", Sprites.SplitLineTrans2_10326_5},
    {"Sirius Split Line #10327_1", Sprites.SplitLine_10327_1},
    {"Sirius Split Line Transform 1 #10327_1", Sprites.SplitLineTrans1_10327_1},
    {"Sirius Split Line Transform 2 #10327_1", Sprites.SplitLineTrans2_10327_1},
    {"Sirius Split Line #10327_2", Sprites.SplitLine_10327_2},
    {"Sirius Split Line Transform 1 #10327_2", Sprites.SplitLineTrans1_10327_2},
    {"Sirius Split Line Transform 2 #10327_2", Sprites.SplitLineTrans2_10327_2},
    {"Sirius Split Line #10327_3", Sprites.SplitLine_10327_3},
    {"Sirius Split Line Transform 1 #10327_3", Sprites.SplitLineTrans1_10327_3},
    {"Sirius Split Line Transform 2 #10327_3", Sprites.SplitLineTrans2_10327_3},
    {"Sirius Split Line #10327_4", Sprites.SplitLine_10327_4},
    {"Sirius Split Line Transform 1 #10327_4", Sprites.SplitLineTrans1_10327_4},
    {"Sirius Split Line Transform 2 #10327_4", Sprites.SplitLineTrans2_10327_4},
    {"Sirius Split Line #10328_1", Sprites.SplitLine_10328_1},
    {"Sirius Split Line Transform 1 #10328_1", Sprites.SplitLineTrans1_10328_1},
    {"Sirius Split Line Transform 2 #10328_1", Sprites.SplitLineTrans2_10328_1},
    {"Sirius Split Line #10328_2", Sprites.SplitLine_10328_2},
    {"Sirius Split Line Transform 1 #10328_2", Sprites.SplitLineTrans1_10328_2},
    {"Sirius Split Line Transform 2 #10328_2", Sprites.SplitLineTrans2_10328_2},
    {"Sirius Split Line #10328_3", Sprites.SplitLine_10328_3},
    {"Sirius Split Line Transform 1 #10328_3", Sprites.SplitLineTrans1_10328_3},
    {"Sirius Split Line Transform 2 #10328_3", Sprites.SplitLineTrans2_10328_3},
    {"Sirius Split Line #10328_4", Sprites.SplitLine_10328_4},
    {"Sirius Split Line Transform 1 #10328_4", Sprites.SplitLineTrans1_10328_4},
    {"Sirius Split Line Transform 2 #10328_4", Sprites.SplitLineTrans2_10328_4},
    {"Sirius Split Line #10328_5", Sprites.SplitLine_10328_5},
    {"Sirius Split Line Transform 1 #10328_5", Sprites.SplitLineTrans1_10328_5},
    {"Sirius Split Line Transform 2 #10328_5", Sprites.SplitLineTrans2_10328_5},
    {"Sirius Split Line #10340", Sprites.SplitLine_10340},
    {"Sirius Split Line Transform 1 #10340", Sprites.SplitLineTrans1_10340},
    {"Sirius Split Line Transform 2 #10340", Sprites.SplitLineTrans2_10340},
    {"Sirius Split Line #10350", Sprites.SplitLine_10350},
    {"Sirius Split Line Transform 1 #10350", Sprites.SplitLineTrans1_10350},
    {"Sirius Split Line Transform 2 #10350", Sprites.SplitLineTrans2_10350},
    {"Sirius Split Line #10360", Sprites.SplitLine_10360},
    {"Sirius Split Line Transform 1 #10360", Sprites.SplitLineTrans1_10360},
    {"Sirius Split Line Transform 2 #10360", Sprites.SplitLineTrans2_10360},
    {"Sirius Split Line #10361", Sprites.SplitLine_10361},
    {"Sirius Split Line Transform 1 #10361", Sprites.SplitLineTrans1_10361},
    {"Sirius Split Line Transform 2 #10361", Sprites.SplitLineTrans2_10361},
    {"Sirius Split Line #10390", Sprites.SplitLine_10390},
    {"Sirius Split Line Transform 1 #10390", Sprites.SplitLineTrans1_10390},
    {"Sirius Split Line Transform 2 #10390", Sprites.SplitLineTrans2_10390},
    {"Sirius Split Line #10391", Sprites.SplitLine_10391},
    {"Sirius Split Line Transform 1 #10391", Sprites.SplitLineTrans1_10391},
    {"Sirius Split Line Transform 2 #10391", Sprites.SplitLineTrans2_10391},
    {"Sirius Split Line #10392", Sprites.SplitLine_10392},
    {"Sirius Split Line Transform 1 #10392", Sprites.SplitLineTrans1_10392},
    {"Sirius Split Line Transform 2 #10392", Sprites.SplitLineTrans2_10392},
    {"Sirius Split Line #10393", Sprites.SplitLine_10393},
    {"Sirius Split Line Transform 1 #10393", Sprites.SplitLineTrans1_10393},
    {"Sirius Split Line Transform 2 #10393", Sprites.SplitLineTrans2_10393},
    {"Sirius Split Line #1040", Sprites.SplitLine_1040},
    {"Sirius Split Line Transform 1 #1040", Sprites.SplitLineTrans1_1040},
    {"Sirius Split Line Transform 2 #1040", Sprites.SplitLineTrans2_1040},
    {"Sirius Split Line #1050", Sprites.SplitLine_1050},
    {"Sirius Split Line Transform 1 #1050", Sprites.SplitLineTrans1_1050},
    {"Sirius Split Line Transform 2 #1050", Sprites.SplitLineTrans2_1050},
    {"Sirius Split Line #1060a", Sprites.SplitLine_1060a},
    {"Sirius Split Line Transform 1 #1060a", Sprites.SplitLineTrans1_1060a},
    {"Sirius Split Line Transform 2 #1060a", Sprites.SplitLineTrans2_1060a},
    {"Sirius Split Line #1060b", Sprites.SplitLine_1060b},
    {"Sirius Split Line Transform 1 #1060b", Sprites.SplitLineTrans1_1060b},
    {"Sirius Split Line Transform 2 #1060b", Sprites.SplitLineTrans2_1060b},
    {"Sirius Split Line #2", Sprites.SplitLine_2},
    {"Sirius Split Line Transform 1 #2", Sprites.SplitLineTrans1_2},
    {"Sirius Split Line Transform 2 #2", Sprites.SplitLineTrans2_2},
    {"Sirius Split Line #2010", Sprites.SplitLine_2010},
    {"Sirius Split Line Transform 1 #2010", Sprites.SplitLineTrans1_2010},
    {"Sirius Split Line Transform 2 #2010", Sprites.SplitLineTrans2_2010},
    {"Sirius Split Line #2020", Sprites.SplitLine_2020},
    {"Sirius Split Line Transform 1 #2020", Sprites.SplitLineTrans1_2020},
    {"Sirius Split Line Transform 2 #2020", Sprites.SplitLineTrans2_2020},
    {"Sirius Split Line #2030", Sprites.SplitLine_2030},
    {"Sirius Split Line Transform 1 #2030", Sprites.SplitLineTrans1_2030},
    {"Sirius Split Line Transform 2 #2030", Sprites.SplitLineTrans2_2030},
    {"Sirius Split Line #2040a", Sprites.SplitLine_2040a},
    {"Sirius Split Line Transform 1 #2040a", Sprites.SplitLineTrans1_2040a},
    {"Sirius Split Line Transform 2 #2040a", Sprites.SplitLineTrans2_2040a},
    {"Sirius Split Line #2040b", Sprites.SplitLine_2040b},
    {"Sirius Split Line Transform 1 #2040b", Sprites.SplitLineTrans1_2040b},
    {"Sirius Split Line Transform 2 #2040b", Sprites.SplitLineTrans2_2040b},
    {"Sirius Split Line #2050", Sprites.SplitLine_2050},
    {"Sirius Split Line Transform 1 #2050", Sprites.SplitLineTrans1_2050},
    {"Sirius Split Line Transform 2 #2050", Sprites.SplitLineTrans2_2050},
    {"Sirius Split Line #3", Sprites.SplitLine_3},
    {"Sirius Split Line Transform 1 #3", Sprites.SplitLineTrans1_3},
    {"Sirius Split Line Transform 2 #3", Sprites.SplitLineTrans2_3},
    {"Sirius Split Line #3010", Sprites.SplitLine_3010},
    {"Sirius Split Line Transform 1 #3010", Sprites.SplitLineTrans1_3010},
    {"Sirius Split Line Transform 2 #3010", Sprites.SplitLineTrans2_3010},
    {"Sirius Split Line #3020", Sprites.SplitLine_3020},
    {"Sirius Split Line Transform 1 #3020", Sprites.SplitLineTrans1_3020},
    {"Sirius Split Line Transform 2 #3020", Sprites.SplitLineTrans2_3020},
    {"Sirius Split Line #3030", Sprites.SplitLine_3030},
    {"Sirius Split Line Transform 1 #3030", Sprites.SplitLineTrans1_3030},
    {"Sirius Split Line Transform 2 #3030", Sprites.SplitLineTrans2_3030},
    {"Sirius Split Line #3040", Sprites.SplitLine_3040},
    {"Sirius Split Line Transform 1 #3040", Sprites.SplitLineTrans1_3040},
    {"Sirius Split Line Transform 2 #3040", Sprites.SplitLineTrans2_3040},
    {"Sirius Split Line #3050", Sprites.SplitLine_3050},
    {"Sirius Split Line Transform 1 #3050", Sprites.SplitLineTrans1_3050},
    {"Sirius Split Line Transform 2 #3050", Sprites.SplitLineTrans2_3050},
    {"Sirius Split Line #4", Sprites.SplitLine_4},
    {"Sirius Split Line Transform 1 #4", Sprites.SplitLineTrans1_4},
    {"Sirius Split Line Transform 2 #4", Sprites.SplitLineTrans2_4},
    {"Sirius Split Line #4010", Sprites.SplitLine_4010},
    {"Sirius Split Line Transform 1 #4010", Sprites.SplitLineTrans1_4010},
    {"Sirius Split Line Transform 2 #4010", Sprites.SplitLineTrans2_4010},
    {"Sirius Split Line #4020", Sprites.SplitLine_4020},
    {"Sirius Split Line Transform 1 #4020", Sprites.SplitLineTrans1_4020},
    {"Sirius Split Line Transform 2 #4020", Sprites.SplitLineTrans2_4020},
    {"Sirius Split Line #4030", Sprites.SplitLine_4030},
    {"Sirius Split Line Transform 1 #4030", Sprites.SplitLineTrans1_4030},
    {"Sirius Split Line Transform 2 #4030", Sprites.SplitLineTrans2_4030},
    {"Sirius Split Line #4040", Sprites.SplitLine_4040},
    {"Sirius Split Line Transform 1 #4040", Sprites.SplitLineTrans1_4040},
    {"Sirius Split Line Transform 2 #4040", Sprites.SplitLineTrans2_4040},
    {"Sirius Split Line #4050", Sprites.SplitLine_4050},
    {"Sirius Split Line Transform 1 #4050", Sprites.SplitLineTrans1_4050},
    {"Sirius Split Line Transform 2 #4050", Sprites.SplitLineTrans2_4050},
    {"Sirius Split Line #5", Sprites.SplitLine_5},
    {"Sirius Split Line Transform 1 #5", Sprites.SplitLineTrans1_5},
    {"Sirius Split Line Transform 2 #5", Sprites.SplitLineTrans2_5},
    {"Sirius Split Line #6", Sprites.SplitLine_6},
    {"Sirius Split Line Transform 1 #6", Sprites.SplitLineTrans1_6},
    {"Sirius Split Line Transform 2 #6", Sprites.SplitLineTrans2_6},
    {"Sirius Split Line #7", Sprites.SplitLine_7},
    {"Sirius Split Line Transform 1 #7", Sprites.SplitLineTrans1_7},
    {"Sirius Split Line Transform 2 #7", Sprites.SplitLineTrans2_7},
    {"Sirius Split Line #8", Sprites.SplitLine_8},
    {"Sirius Split Line Transform 1 #8", Sprites.SplitLineTrans1_8},
    {"Sirius Split Line Transform 2 #8", Sprites.SplitLineTrans2_8},
    {"Sirius Split Line #9", Sprites.SplitLine_9},
    {"Sirius Split Line Transform 1 #9", Sprites.SplitLineTrans1_9},
    {"Sirius Split Line Transform 2 #9", Sprites.SplitLineTrans2_9},
});