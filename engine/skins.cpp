using namespace std;

class Sprites {
	public:

	int Stage = 0;
	int Judgeline = 1;
	int NormalNote = 2;
	int NormalNoteLeft = 2000;
	int NormalNoteMiddle = 2001;
	int NormalNoteRight = 2002;
	int CriticalNote = 3;
	int CriticalNoteLeft = 3000;
	int CriticalNoteMiddle = 3001;
	int CriticalNoteRight = 3002;
	int HoldNote = 4;
	int HoldNoteLeft = 4000;
	int HoldNoteMiddle = 4001;
	int HoldNoteRight = 4002;
	int ScratchNote = 5;
	int ScratchNoteLeft = 5000;
	int ScratchNoteMiddle = 5001;
	int ScratchNoteRight = 5002;
	int ScratchArrow = 6;
	int Hold = 7;
	int Scratch = 8;
	int StageBackground = 9;
	int TouchFeedback = 10;
	int TouchTick = 11;
	int TouchScratchTick = 12;
	int SyncLine = 13;
	int HiddenLine = 14;
	int JudgePerfectPlus = 15;
	int JudgePerfect = 16;
	int JudgeGreat = 17;
	int JudgeGood = 18;
	int JudgeBad = 19;
	int JudgeMiss = 20;
	int JudgeAuto = 21;
	int GridYellow = 22;
	int SplitLine_1 = 23;
	int SplitLineTrans1_1 = 24;
	int SplitLineTrans2_1 = 25;
	int SplitLine_10010 = 26;
	int SplitLineTrans1_10010 = 27;
	int SplitLineTrans2_10010 = 28;
	int SplitLine_10020 = 29;
	int SplitLineTrans1_10020 = 30;
	int SplitLineTrans2_10020 = 31;
	int SplitLine_10030 = 32;
	int SplitLineTrans1_10030 = 33;
	int SplitLineTrans2_10030 = 34;
	int SplitLine_10040 = 35;
	int SplitLineTrans1_10040 = 36;
	int SplitLineTrans2_10040 = 37;
	int SplitLine_10050 = 38;
	int SplitLineTrans1_10050 = 39;
	int SplitLineTrans2_10050 = 40;
	int SplitLine_10060 = 41;
	int SplitLineTrans1_10060 = 42;
	int SplitLineTrans2_10060 = 43;
	int SplitLine_10070 = 44;
	int SplitLineTrans1_10070 = 45;
	int SplitLineTrans2_10070 = 46;
	int SplitLine_1010 = 47;
	int SplitLineTrans1_1010 = 48;
	int SplitLineTrans2_1010 = 49;
	int SplitLine_10100 = 50;
	int SplitLineTrans1_10100 = 51;
	int SplitLineTrans2_10100 = 52;
	int SplitLine_10110 = 53;
	int SplitLineTrans1_10110 = 54;
	int SplitLineTrans2_10110 = 55;
	int SplitLine_10120 = 56;
	int SplitLineTrans1_10120 = 57;
	int SplitLineTrans2_10120 = 58;
	int SplitLine_10130 = 59;
	int SplitLineTrans1_10130 = 60;
	int SplitLineTrans2_10130 = 61;
	int SplitLine_10140 = 62;
	int SplitLineTrans1_10140 = 63;
	int SplitLineTrans2_10140 = 64;
	int SplitLine_10150 = 65;
	int SplitLineTrans1_10150 = 66;
	int SplitLineTrans2_10150 = 67;
	int SplitLine_10160 = 68;
	int SplitLineTrans1_10160 = 69;
	int SplitLineTrans2_10160 = 70;
	int SplitLine_10161 = 71;
	int SplitLineTrans1_10161 = 72;
	int SplitLineTrans2_10161 = 73;
	int SplitLine_10162 = 74;
	int SplitLineTrans1_10162 = 75;
	int SplitLineTrans2_10162 = 76;
	int SplitLine_10170 = 77;
	int SplitLineTrans1_10170 = 78;
	int SplitLineTrans2_10170 = 79;
	int SplitLine_10180 = 80;
	int SplitLineTrans1_10180 = 81;
	int SplitLineTrans2_10180 = 82;
	int SplitLine_10190 = 83;
	int SplitLineTrans1_10190 = 84;
	int SplitLineTrans2_10190 = 85;
	int SplitLine_10191 = 86;
	int SplitLineTrans1_10191 = 87;
	int SplitLineTrans2_10191 = 88;
	int SplitLine_1020 = 89;
	int SplitLineTrans1_1020 = 90;
	int SplitLineTrans2_1020 = 91;
	int SplitLine_10200 = 92;
	int SplitLineTrans1_10200 = 93;
	int SplitLineTrans2_10200 = 94;
	int SplitLine_10220 = 95;
	int SplitLineTrans1_10220 = 96;
	int SplitLineTrans2_10220 = 97;
	int SplitLine_10230 = 98;
	int SplitLineTrans1_10230 = 99;
	int SplitLineTrans2_10230 = 100;
	int SplitLine_10240 = 101;
	int SplitLineTrans1_10240 = 102;
	int SplitLineTrans2_10240 = 103;
	int SplitLine_10250 = 104;
	int SplitLineTrans1_10250 = 105;
	int SplitLineTrans2_10250 = 106;
	int SplitLine_10260 = 107;
	int SplitLineTrans1_10260 = 108;
	int SplitLineTrans2_10260 = 109;
	int SplitLine_10270 = 110;
	int SplitLineTrans1_10270 = 111;
	int SplitLineTrans2_10270 = 112;
	int SplitLine_10280 = 113;
	int SplitLineTrans1_10280 = 114;
	int SplitLineTrans2_10280 = 115;
	int SplitLine_10290 = 116;
	int SplitLineTrans1_10290 = 117;
	int SplitLineTrans2_10290 = 118;
	int SplitLine_1030 = 119;
	int SplitLineTrans1_1030 = 120;
	int SplitLineTrans2_1030 = 121;
	int SplitLine_10300 = 122;
	int SplitLineTrans1_10300 = 123;
	int SplitLineTrans2_10300 = 124;
	int SplitLine_10310 = 125;
	int SplitLineTrans1_10310 = 126;
	int SplitLineTrans2_10310 = 127;
	int SplitLine_10320 = 128;
	int SplitLineTrans1_10320 = 129;
	int SplitLineTrans2_10320 = 130;
	int SplitLine_10321_1 = 131;
	int SplitLineTrans1_10321_1 = 132;
	int SplitLineTrans2_10321_1 = 133;
	int SplitLine_10321_2 = 134;
	int SplitLineTrans1_10321_2 = 135;
	int SplitLineTrans2_10321_2 = 136;
	int SplitLine_10321_3 = 137;
	int SplitLineTrans1_10321_3 = 138;
	int SplitLineTrans2_10321_3 = 139;
	int SplitLine_10321_4 = 140;
	int SplitLineTrans1_10321_4 = 141;
	int SplitLineTrans2_10321_4 = 142;
	int SplitLine_10321_5 = 143;
	int SplitLineTrans1_10321_5 = 144;
	int SplitLineTrans2_10321_5 = 145;
	int SplitLine_10322_1 = 146;
	int SplitLineTrans1_10322_1 = 147;
	int SplitLineTrans2_10322_1 = 148;
	int SplitLine_10322_2 = 149;
	int SplitLineTrans1_10322_2 = 150;
	int SplitLineTrans2_10322_2 = 151;
	int SplitLine_10322_3 = 152;
	int SplitLineTrans1_10322_3 = 153;
	int SplitLineTrans2_10322_3 = 154;
	int SplitLine_10322_4 = 155;
	int SplitLineTrans1_10322_4 = 156;
	int SplitLineTrans2_10322_4 = 157;
	int SplitLine_10322_5 = 158;
	int SplitLineTrans1_10322_5 = 159;
	int SplitLineTrans2_10322_5 = 160;
	int SplitLine_10323_1 = 161;
	int SplitLineTrans1_10323_1 = 162;
	int SplitLineTrans2_10323_1 = 163;
	int SplitLine_10323_2 = 164;
	int SplitLineTrans1_10323_2 = 165;
	int SplitLineTrans2_10323_2 = 166;
	int SplitLine_10323_3 = 167;
	int SplitLineTrans1_10323_3 = 168;
	int SplitLineTrans2_10323_3 = 169;
	int SplitLine_10323_4 = 170;
	int SplitLineTrans1_10323_4 = 171;
	int SplitLineTrans2_10323_4 = 172;
	int SplitLine_10323_5 = 173;
	int SplitLineTrans1_10323_5 = 174;
	int SplitLineTrans2_10323_5 = 175;
	int SplitLine_10324_1 = 176;
	int SplitLineTrans1_10324_1 = 177;
	int SplitLineTrans2_10324_1 = 178;
	int SplitLine_10324_2 = 179;
	int SplitLineTrans1_10324_2 = 180;
	int SplitLineTrans2_10324_2 = 181;
	int SplitLine_10324_3 = 182;
	int SplitLineTrans1_10324_3 = 183;
	int SplitLineTrans2_10324_3 = 184;
	int SplitLine_10325_1 = 185;
	int SplitLineTrans1_10325_1 = 186;
	int SplitLineTrans2_10325_1 = 187;
	int SplitLine_10325_2 = 188;
	int SplitLineTrans1_10325_2 = 189;
	int SplitLineTrans2_10325_2 = 190;
	int SplitLine_10325_3 = 191;
	int SplitLineTrans1_10325_3 = 192;
	int SplitLineTrans2_10325_3 = 193;
	int SplitLine_10325_4 = 194;
	int SplitLineTrans1_10325_4 = 195;
	int SplitLineTrans2_10325_4 = 196;
	int SplitLine_10326_1 = 197;
	int SplitLineTrans1_10326_1 = 198;
	int SplitLineTrans2_10326_1 = 199;
	int SplitLine_10326_2 = 200;
	int SplitLineTrans1_10326_2 = 201;
	int SplitLineTrans2_10326_2 = 202;
	int SplitLine_10326_3 = 203;
	int SplitLineTrans1_10326_3 = 204;
	int SplitLineTrans2_10326_3 = 205;
	int SplitLine_10326_4 = 206;
	int SplitLineTrans1_10326_4 = 207;
	int SplitLineTrans2_10326_4 = 208;
	int SplitLine_10326_5 = 209;
	int SplitLineTrans1_10326_5 = 210;
	int SplitLineTrans2_10326_5 = 211;
	int SplitLine_10327_1 = 212;
	int SplitLineTrans1_10327_1 = 213;
	int SplitLineTrans2_10327_1 = 214;
	int SplitLine_10327_2 = 215;
	int SplitLineTrans1_10327_2 = 216;
	int SplitLineTrans2_10327_2 = 217;
	int SplitLine_10327_3 = 218;
	int SplitLineTrans1_10327_3 = 219;
	int SplitLineTrans2_10327_3 = 220;
	int SplitLine_10327_4 = 221;
	int SplitLineTrans1_10327_4 = 222;
	int SplitLineTrans2_10327_4 = 223;
	int SplitLine_10328_1 = 224;
	int SplitLineTrans1_10328_1 = 225;
	int SplitLineTrans2_10328_1 = 226;
	int SplitLine_10328_2 = 227;
	int SplitLineTrans1_10328_2 = 228;
	int SplitLineTrans2_10328_2 = 229;
	int SplitLine_10328_3 = 230;
	int SplitLineTrans1_10328_3 = 231;
	int SplitLineTrans2_10328_3 = 232;
	int SplitLine_10328_4 = 233;
	int SplitLineTrans1_10328_4 = 234;
	int SplitLineTrans2_10328_4 = 235;
	int SplitLine_10328_5 = 236;
	int SplitLineTrans1_10328_5 = 237;
	int SplitLineTrans2_10328_5 = 238;
	int SplitLine_10330 = 239;
	int SplitLineTrans1_10330 = 240;
	int SplitLineTrans2_10330 = 241;
	int SplitLine_10340 = 242;
	int SplitLineTrans1_10340 = 243;
	int SplitLineTrans2_10340 = 244;
	int SplitLine_10350 = 245;
	int SplitLineTrans1_10350 = 246;
	int SplitLineTrans2_10350 = 247;
	int SplitLine_10360 = 248;
	int SplitLineTrans1_10360 = 249;
	int SplitLineTrans2_10360 = 250;
	int SplitLine_10361 = 251;
	int SplitLineTrans1_10361 = 252;
	int SplitLineTrans2_10361 = 253;
	int SplitLine_10370 = 254;
	int SplitLineTrans1_10370 = 255;
	int SplitLineTrans2_10370 = 256;
	int SplitLine_10380 = 257;
	int SplitLineTrans1_10380 = 258;
	int SplitLineTrans2_10380 = 259;
	int SplitLine_10390 = 260;
	int SplitLineTrans1_10390 = 261;
	int SplitLineTrans2_10390 = 262;
	int SplitLine_10391 = 263;
	int SplitLineTrans1_10391 = 264;
	int SplitLineTrans2_10391 = 265;
	int SplitLine_10392 = 266;
	int SplitLineTrans1_10392 = 267;
	int SplitLineTrans2_10392 = 268;
	int SplitLine_10393 = 269;
	int SplitLineTrans1_10393 = 270;
	int SplitLineTrans2_10393 = 271;
	int SplitLine_1040 = 272;
	int SplitLineTrans1_1040 = 273;
	int SplitLineTrans2_1040 = 274;
	int SplitLine_10400 = 275;
	int SplitLineTrans1_10400 = 276;
	int SplitLineTrans2_10400 = 277;
	int SplitLine_10410 = 278;
	int SplitLineTrans1_10410 = 279;
	int SplitLineTrans2_10410 = 280;
	int SplitLine_10420 = 281;
	int SplitLineTrans1_10420 = 282;
	int SplitLineTrans2_10420 = 283;
	int SplitLine_10430 = 284;
	int SplitLineTrans1_10430 = 285;
	int SplitLineTrans2_10430 = 286;
	int SplitLine_10440 = 287;
	int SplitLineTrans1_10440 = 288;
	int SplitLineTrans2_10440 = 289;
	int SplitLine_10450 = 290;
	int SplitLineTrans1_10450 = 291;
	int SplitLineTrans2_10450 = 292;
	int SplitLine_10460 = 293;
	int SplitLineTrans1_10460 = 294;
	int SplitLineTrans2_10460 = 295;
	int SplitLine_10461 = 296;
	int SplitLineTrans1_10461 = 297;
	int SplitLineTrans2_10461 = 298;
	int SplitLine_10470 = 299;
	int SplitLineTrans1_10470 = 300;
	int SplitLineTrans2_10470 = 301;
	int SplitLine_10480 = 302;
	int SplitLineTrans1_10480 = 303;
	int SplitLineTrans2_10480 = 304;
	int SplitLine_10481_1 = 305;
	int SplitLineTrans1_10481_1 = 306;
	int SplitLineTrans2_10481_1 = 307;
	int SplitLine_10481_2 = 308;
	int SplitLineTrans1_10481_2 = 309;
	int SplitLineTrans2_10481_2 = 310;
	int SplitLine_10481_3 = 311;
	int SplitLineTrans1_10481_3 = 312;
	int SplitLineTrans2_10481_3 = 313;
	int SplitLine_10482 = 314;
	int SplitLineTrans1_10482 = 315;
	int SplitLineTrans2_10482 = 316;
	int SplitLine_10490 = 317;
	int SplitLineTrans1_10490 = 318;
	int SplitLineTrans2_10490 = 319;
	int SplitLine_1050 = 320;
	int SplitLineTrans1_1050 = 321;
	int SplitLineTrans2_1050 = 322;
	int SplitLine_10500 = 323;
	int SplitLineTrans1_10500 = 324;
	int SplitLineTrans2_10500 = 325;
	int SplitLine_10510_1 = 326;
	int SplitLineTrans1_10510_1 = 327;
	int SplitLineTrans2_10510_1 = 328;
	int SplitLine_10510_2 = 329;
	int SplitLineTrans1_10510_2 = 330;
	int SplitLineTrans2_10510_2 = 331;
	int SplitLine_10510_3 = 332;
	int SplitLineTrans1_10510_3 = 333;
	int SplitLineTrans2_10510_3 = 334;
	int SplitLine_10511_1 = 335;
	int SplitLineTrans1_10511_1 = 336;
	int SplitLineTrans2_10511_1 = 337;
	int SplitLine_10511_2 = 338;
	int SplitLineTrans1_10511_2 = 339;
	int SplitLineTrans2_10511_2 = 340;
	int SplitLine_10511_3 = 341;
	int SplitLineTrans1_10511_3 = 342;
	int SplitLineTrans2_10511_3 = 343;
	int SplitLine_10512_1 = 344;
	int SplitLineTrans1_10512_1 = 345;
	int SplitLineTrans2_10512_1 = 346;
	int SplitLine_10512_2 = 347;
	int SplitLineTrans1_10512_2 = 348;
	int SplitLineTrans2_10512_2 = 349;
	int SplitLine_10513_1 = 350;
	int SplitLineTrans1_10513_1 = 351;
	int SplitLineTrans2_10513_1 = 352;
	int SplitLine_10513_2 = 353;
	int SplitLineTrans1_10513_2 = 354;
	int SplitLineTrans2_10513_2 = 355;
	int SplitLine_10514_1 = 356;
	int SplitLineTrans1_10514_1 = 357;
	int SplitLineTrans2_10514_1 = 358;
	int SplitLine_10514_2 = 359;
	int SplitLineTrans1_10514_2 = 360;
	int SplitLineTrans2_10514_2 = 361;
	int SplitLine_10514_3 = 362;
	int SplitLineTrans1_10514_3 = 363;
	int SplitLineTrans2_10514_3 = 364;
	int SplitLine_10515_1 = 365;
	int SplitLineTrans1_10515_1 = 366;
	int SplitLineTrans2_10515_1 = 367;
	int SplitLine_10515_2 = 368;
	int SplitLineTrans1_10515_2 = 369;
	int SplitLineTrans2_10515_2 = 370;
	int SplitLine_10515_3 = 371;
	int SplitLineTrans1_10515_3 = 372;
	int SplitLineTrans2_10515_3 = 373;
	int SplitLine_10516_1 = 374;
	int SplitLineTrans1_10516_1 = 375;
	int SplitLineTrans2_10516_1 = 376;
	int SplitLine_10516_2 = 377;
	int SplitLineTrans1_10516_2 = 378;
	int SplitLineTrans2_10516_2 = 379;
	int SplitLine_10516_3 = 380;
	int SplitLineTrans1_10516_3 = 381;
	int SplitLineTrans2_10516_3 = 382;
	int SplitLine_10517_1 = 383;
	int SplitLineTrans1_10517_1 = 384;
	int SplitLineTrans2_10517_1 = 385;
	int SplitLine_10517_2 = 386;
	int SplitLineTrans1_10517_2 = 387;
	int SplitLineTrans2_10517_2 = 388;
	int SplitLine_10517_3 = 389;
	int SplitLineTrans1_10517_3 = 390;
	int SplitLineTrans2_10517_3 = 391;
	int SplitLine_10518_1 = 392;
	int SplitLineTrans1_10518_1 = 393;
	int SplitLineTrans2_10518_1 = 394;
	int SplitLine_10518_2 = 395;
	int SplitLineTrans1_10518_2 = 396;
	int SplitLineTrans2_10518_2 = 397;
	int SplitLine_10518_3 = 398;
	int SplitLineTrans1_10518_3 = 399;
	int SplitLineTrans2_10518_3 = 400;
	int SplitLine_10518_4 = 401;
	int SplitLineTrans1_10518_4 = 402;
	int SplitLineTrans2_10518_4 = 403;
	int SplitLine_10518_5 = 404;
	int SplitLineTrans1_10518_5 = 405;
	int SplitLineTrans2_10518_5 = 406;
	int SplitLine_10519_1 = 407;
	int SplitLineTrans1_10519_1 = 408;
	int SplitLineTrans2_10519_1 = 409;
	int SplitLine_10519_2 = 410;
	int SplitLineTrans1_10519_2 = 411;
	int SplitLineTrans2_10519_2 = 412;
	int SplitLine_10519_3 = 413;
	int SplitLineTrans1_10519_3 = 414;
	int SplitLineTrans2_10519_3 = 415;
	int SplitLine_10519_4 = 416;
	int SplitLineTrans1_10519_4 = 417;
	int SplitLineTrans2_10519_4 = 418;
	int SplitLine_10519_5 = 419;
	int SplitLineTrans1_10519_5 = 420;
	int SplitLineTrans2_10519_5 = 421;
	int SplitLine_10530 = 422;
	int SplitLineTrans1_10530 = 423;
	int SplitLineTrans2_10530 = 424;
	int SplitLine_10540 = 425;
	int SplitLineTrans1_10540 = 426;
	int SplitLineTrans2_10540 = 427;
	int SplitLine_10550 = 428;
	int SplitLineTrans1_10550 = 429;
	int SplitLineTrans2_10550 = 430;
	int SplitLine_10560 = 431;
	int SplitLineTrans1_10560 = 432;
	int SplitLineTrans2_10560 = 433;
	int SplitLine_10570 = 434;
	int SplitLineTrans1_10570 = 435;
	int SplitLineTrans2_10570 = 436;
	int SplitLine_10580 = 437;
	int SplitLineTrans1_10580 = 438;
	int SplitLineTrans2_10580 = 439;
	int SplitLine_10590 = 440;
	int SplitLineTrans1_10590 = 441;
	int SplitLineTrans2_10590 = 442;
	int SplitLine_10600 = 443;
	int SplitLineTrans1_10600 = 444;
	int SplitLineTrans2_10600 = 445;
	int SplitLine_1060a = 446;
	int SplitLineTrans1_1060a = 447;
	int SplitLineTrans2_1060a = 448;
	int SplitLine_1060b = 449;
	int SplitLineTrans1_1060b = 450;
	int SplitLineTrans2_1060b = 451;
	int SplitLine_10610 = 452;
	int SplitLineTrans1_10610 = 453;
	int SplitLineTrans2_10610 = 454;
	int SplitLine_10620 = 455;
	int SplitLineTrans1_10620 = 456;
	int SplitLineTrans2_10620 = 457;
	int SplitLine_10630 = 458;
	int SplitLineTrans1_10630 = 459;
	int SplitLineTrans2_10630 = 460;
	int SplitLine_10631 = 461;
	int SplitLineTrans1_10631 = 462;
	int SplitLineTrans2_10631 = 463;
	int SplitLine_10640 = 464;
	int SplitLineTrans1_10640 = 465;
	int SplitLineTrans2_10640 = 466;
	int SplitLine_10650 = 467;
	int SplitLineTrans1_10650 = 468;
	int SplitLineTrans2_10650 = 469;
	int SplitLine_10660 = 470;
	int SplitLineTrans1_10660 = 471;
	int SplitLineTrans2_10660 = 472;
	int SplitLine_10670 = 473;
	int SplitLineTrans1_10670 = 474;
	int SplitLineTrans2_10670 = 475;
	int SplitLine_10680 = 476;
	int SplitLineTrans1_10680 = 477;
	int SplitLineTrans2_10680 = 478;
	int SplitLine_10690 = 479;
	int SplitLineTrans1_10690 = 480;
	int SplitLineTrans2_10690 = 481;
	int SplitLine_10710 = 482;
	int SplitLineTrans1_10710 = 483;
	int SplitLineTrans2_10710 = 484;
	int SplitLine_10720 = 485;
	int SplitLineTrans1_10720 = 486;
	int SplitLineTrans2_10720 = 487;
	int SplitLine_2 = 488;
	int SplitLineTrans1_2 = 489;
	int SplitLineTrans2_2 = 490;
	int SplitLine_2010 = 491;
	int SplitLineTrans1_2010 = 492;
	int SplitLineTrans2_2010 = 493;
	int SplitLine_2020 = 494;
	int SplitLineTrans1_2020 = 495;
	int SplitLineTrans2_2020 = 496;
	int SplitLine_2030 = 497;
	int SplitLineTrans1_2030 = 498;
	int SplitLineTrans2_2030 = 499;
	int SplitLine_2040a = 500;
	int SplitLineTrans1_2040a = 501;
	int SplitLineTrans2_2040a = 502;
	int SplitLine_2040b = 503;
	int SplitLineTrans1_2040b = 504;
	int SplitLineTrans2_2040b = 505;
	int SplitLine_2050 = 506;
	int SplitLineTrans1_2050 = 507;
	int SplitLineTrans2_2050 = 508;
	int SplitLine_3 = 509;
	int SplitLineTrans1_3 = 510;
	int SplitLineTrans2_3 = 511;
	int SplitLine_3010 = 512;
	int SplitLineTrans1_3010 = 513;
	int SplitLineTrans2_3010 = 514;
	int SplitLine_3020 = 515;
	int SplitLineTrans1_3020 = 516;
	int SplitLineTrans2_3020 = 517;
	int SplitLine_3030 = 518;
	int SplitLineTrans1_3030 = 519;
	int SplitLineTrans2_3030 = 520;
	int SplitLine_3040 = 521;
	int SplitLineTrans1_3040 = 522;
	int SplitLineTrans2_3040 = 523;
	int SplitLine_3050 = 524;
	int SplitLineTrans1_3050 = 525;
	int SplitLineTrans2_3050 = 526;
	int SplitLine_4 = 527;
	int SplitLineTrans1_4 = 528;
	int SplitLineTrans2_4 = 529;
	int SplitLine_4010 = 530;
	int SplitLineTrans1_4010 = 531;
	int SplitLineTrans2_4010 = 532;
	int SplitLine_4020 = 533;
	int SplitLineTrans1_4020 = 534;
	int SplitLineTrans2_4020 = 535;
	int SplitLine_4030 = 536;
	int SplitLineTrans1_4030 = 537;
	int SplitLineTrans2_4030 = 538;
	int SplitLine_4040 = 539;
	int SplitLineTrans1_4040 = 540;
	int SplitLineTrans2_4040 = 541;
	int SplitLine_4050 = 542;
	int SplitLineTrans1_4050 = 543;
	int SplitLineTrans2_4050 = 544;
	int SplitLine_5 = 545;
	int SplitLineTrans1_5 = 546;
	int SplitLineTrans2_5 = 547;
	int SplitLine_6 = 548;
	int SplitLineTrans1_6 = 549;
	int SplitLineTrans2_6 = 550;
	int SplitLine_7 = 551;
	int SplitLineTrans1_7 = 552;
	int SplitLineTrans2_7 = 553;
	int SplitLine_8 = 554;
	int SplitLineTrans1_8 = 555;
	int SplitLineTrans2_8 = 556;
	int SplitLine_9 = 557;
	int SplitLineTrans1_9 = 558;
	int SplitLineTrans2_9 = 559;
}Sprites;

auto skins = defineSkins<class Sprites>({
	{SkinSpriteName.StageCover, Sprites.Stage},
	{SkinSpriteName.JudgmentLine, Sprites.Judgeline},
	{SkinSpriteName.NoteHeadRed, Sprites.NormalNote},
	{"Sirius Note Red Left", Sprites.NormalNoteLeft},
	{"Sirius Note Red Middle", Sprites.NormalNoteMiddle},
	{"Sirius Note Red Right", Sprites.NormalNoteRight},
	{SkinSpriteName.NoteHeadYellow, Sprites.CriticalNote},
	{"Sirius Note Yellow Left", Sprites.CriticalNoteLeft},
	{"Sirius Note Yellow Middle", Sprites.CriticalNoteMiddle},
	{"Sirius Note Yellow Right", Sprites.CriticalNoteRight},
	{SkinSpriteName.NoteHeadBlue, Sprites.HoldNote},
	{"Sirius Note Blue Left", Sprites.HoldNoteLeft},
	{"Sirius Note Blue Middle", Sprites.HoldNoteMiddle},
	{"Sirius Note Blue Right", Sprites.HoldNoteRight},
	{SkinSpriteName.NoteHeadPurple, Sprites.ScratchNote},
	{"Sirius Note Purple Left", Sprites.ScratchNoteLeft},
	{"Sirius Note Purple Middle", Sprites.ScratchNoteMiddle},
	{"Sirius Note Purple Right", Sprites.ScratchNoteRight},
	{SkinSpriteName.DirectionalMarkerPurple, Sprites.ScratchArrow},
	{SkinSpriteName.NoteConnectionBlue, Sprites.Hold},
	{SkinSpriteName.NoteConnectionPurple, Sprites.Scratch},
	{SkinSpriteName.StageBottomBorder, Sprites.StageBackground},
	{SkinSpriteName.StageMiddle, Sprites.TouchFeedback},
	{SkinSpriteName.NoteTickBlue, Sprites.TouchTick},
	{SkinSpriteName.NoteTickPurple, Sprites.TouchScratchTick},
	{SkinSpriteName.Lane, Sprites.SyncLine},
	{"Sirius Hidden Line", Sprites.HiddenLine},
	{"Sirius Judge Perfect+", Sprites.JudgePerfectPlus},
	{"Sirius Judge Perfect", Sprites.JudgePerfect},
	{"Sirius Judge Great", Sprites.JudgeGreat},
	{"Sirius Judge Good", Sprites.JudgeGood},
	{"Sirius Judge Bad", Sprites.JudgeBad},
	{"Sirius Judge Miss", Sprites.JudgeMiss},
	{"Sirius Judge Auto", Sprites.JudgeAuto},
	{SkinSpriteName.GridYellow, Sprites.GridYellow},
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
	{"Sirius Split Line #10270", Sprites.SplitLine_10270},
	{"Sirius Split Line Transform 1 #10270", Sprites.SplitLineTrans1_10270},
	{"Sirius Split Line Transform 2 #10270", Sprites.SplitLineTrans2_10270},
	{"Sirius Split Line #10280", Sprites.SplitLine_10280},
	{"Sirius Split Line Transform 1 #10280", Sprites.SplitLineTrans1_10280},
	{"Sirius Split Line Transform 2 #10280", Sprites.SplitLineTrans2_10280},
	{"Sirius Split Line #10290", Sprites.SplitLine_10290},
	{"Sirius Split Line Transform 1 #10290", Sprites.SplitLineTrans1_10290},
	{"Sirius Split Line Transform 2 #10290", Sprites.SplitLineTrans2_10290},
	{"Sirius Split Line #1030", Sprites.SplitLine_1030},
	{"Sirius Split Line Transform 1 #1030", Sprites.SplitLineTrans1_1030},
	{"Sirius Split Line Transform 2 #1030", Sprites.SplitLineTrans2_1030},
	{"Sirius Split Line #10300", Sprites.SplitLine_10300},
	{"Sirius Split Line Transform 1 #10300", Sprites.SplitLineTrans1_10300},
	{"Sirius Split Line Transform 2 #10300", Sprites.SplitLineTrans2_10300},
	{"Sirius Split Line #10310", Sprites.SplitLine_10310},
	{"Sirius Split Line Transform 1 #10310", Sprites.SplitLineTrans1_10310},
	{"Sirius Split Line Transform 2 #10310", Sprites.SplitLineTrans2_10310},
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
	{"Sirius Split Line #10330", Sprites.SplitLine_10330},
	{"Sirius Split Line Transform 1 #10330", Sprites.SplitLineTrans1_10330},
	{"Sirius Split Line Transform 2 #10330", Sprites.SplitLineTrans2_10330},
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
	{"Sirius Split Line #10370", Sprites.SplitLine_10370},
	{"Sirius Split Line Transform 1 #10370", Sprites.SplitLineTrans1_10370},
	{"Sirius Split Line Transform 2 #10370", Sprites.SplitLineTrans2_10370},
	{"Sirius Split Line #10380", Sprites.SplitLine_10380},
	{"Sirius Split Line Transform 1 #10380", Sprites.SplitLineTrans1_10380},
	{"Sirius Split Line Transform 2 #10380", Sprites.SplitLineTrans2_10380},
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
	{"Sirius Split Line #10400", Sprites.SplitLine_10400},
	{"Sirius Split Line Transform 1 #10400", Sprites.SplitLineTrans1_10400},
	{"Sirius Split Line Transform 2 #10400", Sprites.SplitLineTrans2_10400},
	{"Sirius Split Line #10410", Sprites.SplitLine_10410},
	{"Sirius Split Line Transform 1 #10410", Sprites.SplitLineTrans1_10410},
	{"Sirius Split Line Transform 2 #10410", Sprites.SplitLineTrans2_10410},
	{"Sirius Split Line #10420", Sprites.SplitLine_10420},
	{"Sirius Split Line Transform 1 #10420", Sprites.SplitLineTrans1_10420},
	{"Sirius Split Line Transform 2 #10420", Sprites.SplitLineTrans2_10420},
	{"Sirius Split Line #10430", Sprites.SplitLine_10430},
	{"Sirius Split Line Transform 1 #10430", Sprites.SplitLineTrans1_10430},
	{"Sirius Split Line Transform 2 #10430", Sprites.SplitLineTrans2_10430},
	{"Sirius Split Line #10440", Sprites.SplitLine_10440},
	{"Sirius Split Line Transform 1 #10440", Sprites.SplitLineTrans1_10440},
	{"Sirius Split Line Transform 2 #10440", Sprites.SplitLineTrans2_10440},
	{"Sirius Split Line #10450", Sprites.SplitLine_10450},
	{"Sirius Split Line Transform 1 #10450", Sprites.SplitLineTrans1_10450},
	{"Sirius Split Line Transform 2 #10450", Sprites.SplitLineTrans2_10450},
	{"Sirius Split Line #10460", Sprites.SplitLine_10460},
	{"Sirius Split Line Transform 1 #10460", Sprites.SplitLineTrans1_10460},
	{"Sirius Split Line Transform 2 #10460", Sprites.SplitLineTrans2_10460},
	{"Sirius Split Line #10461", Sprites.SplitLine_10461},
	{"Sirius Split Line Transform 1 #10461", Sprites.SplitLineTrans1_10461},
	{"Sirius Split Line Transform 2 #10461", Sprites.SplitLineTrans2_10461},
	{"Sirius Split Line #10470", Sprites.SplitLine_10470},
	{"Sirius Split Line Transform 1 #10470", Sprites.SplitLineTrans1_10470},
	{"Sirius Split Line Transform 2 #10470", Sprites.SplitLineTrans2_10470},
	{"Sirius Split Line #10480", Sprites.SplitLine_10480},
	{"Sirius Split Line Transform 1 #10480", Sprites.SplitLineTrans1_10480},
	{"Sirius Split Line Transform 2 #10480", Sprites.SplitLineTrans2_10480},
	{"Sirius Split Line #10481_1", Sprites.SplitLine_10481_1},
	{"Sirius Split Line Transform 1 #10481_1", Sprites.SplitLineTrans1_10481_1},
	{"Sirius Split Line Transform 2 #10481_1", Sprites.SplitLineTrans2_10481_1},
	{"Sirius Split Line #10481_2", Sprites.SplitLine_10481_2},
	{"Sirius Split Line Transform 1 #10481_2", Sprites.SplitLineTrans1_10481_2},
	{"Sirius Split Line Transform 2 #10481_2", Sprites.SplitLineTrans2_10481_2},
	{"Sirius Split Line #10481_3", Sprites.SplitLine_10481_3},
	{"Sirius Split Line Transform 1 #10481_3", Sprites.SplitLineTrans1_10481_3},
	{"Sirius Split Line Transform 2 #10481_3", Sprites.SplitLineTrans2_10481_3},
	{"Sirius Split Line #10482", Sprites.SplitLine_10482},
	{"Sirius Split Line Transform 1 #10482", Sprites.SplitLineTrans1_10482},
	{"Sirius Split Line Transform 2 #10482", Sprites.SplitLineTrans2_10482},
	{"Sirius Split Line #10490", Sprites.SplitLine_10490},
	{"Sirius Split Line Transform 1 #10490", Sprites.SplitLineTrans1_10490},
	{"Sirius Split Line Transform 2 #10490", Sprites.SplitLineTrans2_10490},
	{"Sirius Split Line #1050", Sprites.SplitLine_1050},
	{"Sirius Split Line Transform 1 #1050", Sprites.SplitLineTrans1_1050},
	{"Sirius Split Line Transform 2 #1050", Sprites.SplitLineTrans2_1050},
	{"Sirius Split Line #10500", Sprites.SplitLine_10500},
	{"Sirius Split Line Transform 1 #10500", Sprites.SplitLineTrans1_10500},
	{"Sirius Split Line Transform 2 #10500", Sprites.SplitLineTrans2_10500},
	{"Sirius Split Line #10510_1", Sprites.SplitLine_10510_1},
	{"Sirius Split Line Transform 1 #10510_1", Sprites.SplitLineTrans1_10510_1},
	{"Sirius Split Line Transform 2 #10510_1", Sprites.SplitLineTrans2_10510_1},
	{"Sirius Split Line #10510_2", Sprites.SplitLine_10510_2},
	{"Sirius Split Line Transform 1 #10510_2", Sprites.SplitLineTrans1_10510_2},
	{"Sirius Split Line Transform 2 #10510_2", Sprites.SplitLineTrans2_10510_2},
	{"Sirius Split Line #10510_3", Sprites.SplitLine_10510_3},
	{"Sirius Split Line Transform 1 #10510_3", Sprites.SplitLineTrans1_10510_3},
	{"Sirius Split Line Transform 2 #10510_3", Sprites.SplitLineTrans2_10510_3},
	{"Sirius Split Line #10511_1", Sprites.SplitLine_10511_1},
	{"Sirius Split Line Transform 1 #10511_1", Sprites.SplitLineTrans1_10511_1},
	{"Sirius Split Line Transform 2 #10511_1", Sprites.SplitLineTrans2_10511_1},
	{"Sirius Split Line #10511_2", Sprites.SplitLine_10511_2},
	{"Sirius Split Line Transform 1 #10511_2", Sprites.SplitLineTrans1_10511_2},
	{"Sirius Split Line Transform 2 #10511_2", Sprites.SplitLineTrans2_10511_2},
	{"Sirius Split Line #10511_3", Sprites.SplitLine_10511_3},
	{"Sirius Split Line Transform 1 #10511_3", Sprites.SplitLineTrans1_10511_3},
	{"Sirius Split Line Transform 2 #10511_3", Sprites.SplitLineTrans2_10511_3},
	{"Sirius Split Line #10512_1", Sprites.SplitLine_10512_1},
	{"Sirius Split Line Transform 1 #10512_1", Sprites.SplitLineTrans1_10512_1},
	{"Sirius Split Line Transform 2 #10512_1", Sprites.SplitLineTrans2_10512_1},
	{"Sirius Split Line #10512_2", Sprites.SplitLine_10512_2},
	{"Sirius Split Line Transform 1 #10512_2", Sprites.SplitLineTrans1_10512_2},
	{"Sirius Split Line Transform 2 #10512_2", Sprites.SplitLineTrans2_10512_2},
	{"Sirius Split Line #10513_1", Sprites.SplitLine_10513_1},
	{"Sirius Split Line Transform 1 #10513_1", Sprites.SplitLineTrans1_10513_1},
	{"Sirius Split Line Transform 2 #10513_1", Sprites.SplitLineTrans2_10513_1},
	{"Sirius Split Line #10513_2", Sprites.SplitLine_10513_2},
	{"Sirius Split Line Transform 1 #10513_2", Sprites.SplitLineTrans1_10513_2},
	{"Sirius Split Line Transform 2 #10513_2", Sprites.SplitLineTrans2_10513_2},
	{"Sirius Split Line #10514_1", Sprites.SplitLine_10514_1},
	{"Sirius Split Line Transform 1 #10514_1", Sprites.SplitLineTrans1_10514_1},
	{"Sirius Split Line Transform 2 #10514_1", Sprites.SplitLineTrans2_10514_1},
	{"Sirius Split Line #10514_2", Sprites.SplitLine_10514_2},
	{"Sirius Split Line Transform 1 #10514_2", Sprites.SplitLineTrans1_10514_2},
	{"Sirius Split Line Transform 2 #10514_2", Sprites.SplitLineTrans2_10514_2},
	{"Sirius Split Line #10514_3", Sprites.SplitLine_10514_3},
	{"Sirius Split Line Transform 1 #10514_3", Sprites.SplitLineTrans1_10514_3},
	{"Sirius Split Line Transform 2 #10514_3", Sprites.SplitLineTrans2_10514_3},
	{"Sirius Split Line #10515_1", Sprites.SplitLine_10515_1},
	{"Sirius Split Line Transform 1 #10515_1", Sprites.SplitLineTrans1_10515_1},
	{"Sirius Split Line Transform 2 #10515_1", Sprites.SplitLineTrans2_10515_1},
	{"Sirius Split Line #10515_2", Sprites.SplitLine_10515_2},
	{"Sirius Split Line Transform 1 #10515_2", Sprites.SplitLineTrans1_10515_2},
	{"Sirius Split Line Transform 2 #10515_2", Sprites.SplitLineTrans2_10515_2},
	{"Sirius Split Line #10515_3", Sprites.SplitLine_10515_3},
	{"Sirius Split Line Transform 1 #10515_3", Sprites.SplitLineTrans1_10515_3},
	{"Sirius Split Line Transform 2 #10515_3", Sprites.SplitLineTrans2_10515_3},
	{"Sirius Split Line #10516_1", Sprites.SplitLine_10516_1},
	{"Sirius Split Line Transform 1 #10516_1", Sprites.SplitLineTrans1_10516_1},
	{"Sirius Split Line Transform 2 #10516_1", Sprites.SplitLineTrans2_10516_1},
	{"Sirius Split Line #10516_2", Sprites.SplitLine_10516_2},
	{"Sirius Split Line Transform 1 #10516_2", Sprites.SplitLineTrans1_10516_2},
	{"Sirius Split Line Transform 2 #10516_2", Sprites.SplitLineTrans2_10516_2},
	{"Sirius Split Line #10516_3", Sprites.SplitLine_10516_3},
	{"Sirius Split Line Transform 1 #10516_3", Sprites.SplitLineTrans1_10516_3},
	{"Sirius Split Line Transform 2 #10516_3", Sprites.SplitLineTrans2_10516_3},
	{"Sirius Split Line #10517_1", Sprites.SplitLine_10517_1},
	{"Sirius Split Line Transform 1 #10517_1", Sprites.SplitLineTrans1_10517_1},
	{"Sirius Split Line Transform 2 #10517_1", Sprites.SplitLineTrans2_10517_1},
	{"Sirius Split Line #10517_2", Sprites.SplitLine_10517_2},
	{"Sirius Split Line Transform 1 #10517_2", Sprites.SplitLineTrans1_10517_2},
	{"Sirius Split Line Transform 2 #10517_2", Sprites.SplitLineTrans2_10517_2},
	{"Sirius Split Line #10517_3", Sprites.SplitLine_10517_3},
	{"Sirius Split Line Transform 1 #10517_3", Sprites.SplitLineTrans1_10517_3},
	{"Sirius Split Line Transform 2 #10517_3", Sprites.SplitLineTrans2_10517_3},
	{"Sirius Split Line #10518_1", Sprites.SplitLine_10518_1},
	{"Sirius Split Line Transform 1 #10518_1", Sprites.SplitLineTrans1_10518_1},
	{"Sirius Split Line Transform 2 #10518_1", Sprites.SplitLineTrans2_10518_1},
	{"Sirius Split Line #10518_2", Sprites.SplitLine_10518_2},
	{"Sirius Split Line Transform 1 #10518_2", Sprites.SplitLineTrans1_10518_2},
	{"Sirius Split Line Transform 2 #10518_2", Sprites.SplitLineTrans2_10518_2},
	{"Sirius Split Line #10518_3", Sprites.SplitLine_10518_3},
	{"Sirius Split Line Transform 1 #10518_3", Sprites.SplitLineTrans1_10518_3},
	{"Sirius Split Line Transform 2 #10518_3", Sprites.SplitLineTrans2_10518_3},
	{"Sirius Split Line #10518_4", Sprites.SplitLine_10518_4},
	{"Sirius Split Line Transform 1 #10518_4", Sprites.SplitLineTrans1_10518_4},
	{"Sirius Split Line Transform 2 #10518_4", Sprites.SplitLineTrans2_10518_4},
	{"Sirius Split Line #10518_5", Sprites.SplitLine_10518_5},
	{"Sirius Split Line Transform 1 #10518_5", Sprites.SplitLineTrans1_10518_5},
	{"Sirius Split Line Transform 2 #10518_5", Sprites.SplitLineTrans2_10518_5},
	{"Sirius Split Line #10519_1", Sprites.SplitLine_10519_1},
	{"Sirius Split Line Transform 1 #10519_1", Sprites.SplitLineTrans1_10519_1},
	{"Sirius Split Line Transform 2 #10519_1", Sprites.SplitLineTrans2_10519_1},
	{"Sirius Split Line #10519_2", Sprites.SplitLine_10519_2},
	{"Sirius Split Line Transform 1 #10519_2", Sprites.SplitLineTrans1_10519_2},
	{"Sirius Split Line Transform 2 #10519_2", Sprites.SplitLineTrans2_10519_2},
	{"Sirius Split Line #10519_3", Sprites.SplitLine_10519_3},
	{"Sirius Split Line Transform 1 #10519_3", Sprites.SplitLineTrans1_10519_3},
	{"Sirius Split Line Transform 2 #10519_3", Sprites.SplitLineTrans2_10519_3},
	{"Sirius Split Line #10519_4", Sprites.SplitLine_10519_4},
	{"Sirius Split Line Transform 1 #10519_4", Sprites.SplitLineTrans1_10519_4},
	{"Sirius Split Line Transform 2 #10519_4", Sprites.SplitLineTrans2_10519_4},
	{"Sirius Split Line #10519_5", Sprites.SplitLine_10519_5},
	{"Sirius Split Line Transform 1 #10519_5", Sprites.SplitLineTrans1_10519_5},
	{"Sirius Split Line Transform 2 #10519_5", Sprites.SplitLineTrans2_10519_5},
	{"Sirius Split Line #10530", Sprites.SplitLine_10530},
	{"Sirius Split Line Transform 1 #10530", Sprites.SplitLineTrans1_10530},
	{"Sirius Split Line Transform 2 #10530", Sprites.SplitLineTrans2_10530},
	{"Sirius Split Line #10540", Sprites.SplitLine_10540},
	{"Sirius Split Line Transform 1 #10540", Sprites.SplitLineTrans1_10540},
	{"Sirius Split Line Transform 2 #10540", Sprites.SplitLineTrans2_10540},
	{"Sirius Split Line #10550", Sprites.SplitLine_10550},
	{"Sirius Split Line Transform 1 #10550", Sprites.SplitLineTrans1_10550},
	{"Sirius Split Line Transform 2 #10550", Sprites.SplitLineTrans2_10550},
	{"Sirius Split Line #10560", Sprites.SplitLine_10560},
	{"Sirius Split Line Transform 1 #10560", Sprites.SplitLineTrans1_10560},
	{"Sirius Split Line Transform 2 #10560", Sprites.SplitLineTrans2_10560},
	{"Sirius Split Line #10570", Sprites.SplitLine_10570},
	{"Sirius Split Line Transform 1 #10570", Sprites.SplitLineTrans1_10570},
	{"Sirius Split Line Transform 2 #10570", Sprites.SplitLineTrans2_10570},
	{"Sirius Split Line #10580", Sprites.SplitLine_10580},
	{"Sirius Split Line Transform 1 #10580", Sprites.SplitLineTrans1_10580},
	{"Sirius Split Line Transform 2 #10580", Sprites.SplitLineTrans2_10580},
	{"Sirius Split Line #10590", Sprites.SplitLine_10590},
	{"Sirius Split Line Transform 1 #10590", Sprites.SplitLineTrans1_10590},
	{"Sirius Split Line Transform 2 #10590", Sprites.SplitLineTrans2_10590},
	{"Sirius Split Line #10600", Sprites.SplitLine_10600},
	{"Sirius Split Line Transform 1 #10600", Sprites.SplitLineTrans1_10600},
	{"Sirius Split Line Transform 2 #10600", Sprites.SplitLineTrans2_10600},
	{"Sirius Split Line #1060a", Sprites.SplitLine_1060a},
	{"Sirius Split Line Transform 1 #1060a", Sprites.SplitLineTrans1_1060a},
	{"Sirius Split Line Transform 2 #1060a", Sprites.SplitLineTrans2_1060a},
	{"Sirius Split Line #1060b", Sprites.SplitLine_1060b},
	{"Sirius Split Line Transform 1 #1060b", Sprites.SplitLineTrans1_1060b},
	{"Sirius Split Line Transform 2 #1060b", Sprites.SplitLineTrans2_1060b},
	{"Sirius Split Line #10610", Sprites.SplitLine_10610},
	{"Sirius Split Line Transform 1 #10610", Sprites.SplitLineTrans1_10610},
	{"Sirius Split Line Transform 2 #10610", Sprites.SplitLineTrans2_10610},
	{"Sirius Split Line #10620", Sprites.SplitLine_10620},
	{"Sirius Split Line Transform 1 #10620", Sprites.SplitLineTrans1_10620},
	{"Sirius Split Line Transform 2 #10620", Sprites.SplitLineTrans2_10620},
	{"Sirius Split Line #10630", Sprites.SplitLine_10630},
	{"Sirius Split Line Transform 1 #10630", Sprites.SplitLineTrans1_10630},
	{"Sirius Split Line Transform 2 #10630", Sprites.SplitLineTrans2_10630},
	{"Sirius Split Line #10631", Sprites.SplitLine_10631},
	{"Sirius Split Line Transform 1 #10631", Sprites.SplitLineTrans1_10631},
	{"Sirius Split Line Transform 2 #10631", Sprites.SplitLineTrans2_10631},
	{"Sirius Split Line #10640", Sprites.SplitLine_10640},
	{"Sirius Split Line Transform 1 #10640", Sprites.SplitLineTrans1_10640},
	{"Sirius Split Line Transform 2 #10640", Sprites.SplitLineTrans2_10640},
	{"Sirius Split Line #10650", Sprites.SplitLine_10650},
	{"Sirius Split Line Transform 1 #10650", Sprites.SplitLineTrans1_10650},
	{"Sirius Split Line Transform 2 #10650", Sprites.SplitLineTrans2_10650},
	{"Sirius Split Line #10660", Sprites.SplitLine_10660},
	{"Sirius Split Line Transform 1 #10660", Sprites.SplitLineTrans1_10660},
	{"Sirius Split Line Transform 2 #10660", Sprites.SplitLineTrans2_10660},
	{"Sirius Split Line #10670", Sprites.SplitLine_10670},
	{"Sirius Split Line Transform 1 #10670", Sprites.SplitLineTrans1_10670},
	{"Sirius Split Line Transform 2 #10670", Sprites.SplitLineTrans2_10670},
	{"Sirius Split Line #10680", Sprites.SplitLine_10680},
	{"Sirius Split Line Transform 1 #10680", Sprites.SplitLineTrans1_10680},
	{"Sirius Split Line Transform 2 #10680", Sprites.SplitLineTrans2_10680},
	{"Sirius Split Line #10690", Sprites.SplitLine_10690},
	{"Sirius Split Line Transform 1 #10690", Sprites.SplitLineTrans1_10690},
	{"Sirius Split Line Transform 2 #10690", Sprites.SplitLineTrans2_10690},
	{"Sirius Split Line #10700", Sprites.SplitLine_10700},
	{"Sirius Split Line Transform 1 #10700", Sprites.SplitLineTrans1_10700},
	{"Sirius Split Line Transform 2 #10700", Sprites.SplitLineTrans2_10700},
	{"Sirius Split Line #1070a", Sprites.SplitLine_1070a},
	{"Sirius Split Line Transform 1 #1070a", Sprites.SplitLineTrans1_1070a},
	{"Sirius Split Line Transform 2 #1070a", Sprites.SplitLineTrans2_1070a},
	{"Sirius Split Line #1070b", Sprites.SplitLine_1070b},
	{"Sirius Split Line Transform 1 #1070b", Sprites.SplitLineTrans1_1070b},
	{"Sirius Split Line Transform 2 #1070b", Sprites.SplitLineTrans2_1070b},
	{"Sirius Split Line #10710", Sprites.SplitLine_10710},
	{"Sirius Split Line Transform 1 #10710", Sprites.SplitLineTrans1_10710},
	{"Sirius Split Line Transform 2 #10710", Sprites.SplitLineTrans2_10710},
	{"Sirius Split Line #10720", Sprites.SplitLine_10720},
	{"Sirius Split Line Transform 1 #10720", Sprites.SplitLineTrans1_10720},
	{"Sirius Split Line Transform 2 #10720", Sprites.SplitLineTrans2_10720},
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
