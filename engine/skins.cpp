using namespace std;

class Sprites {
	public:

	int Stage = 0;
	int Judgeline = 1;
	int NormalNote = 2;
	int NormalNoteLeft = 3;
	int NormalNoteMiddle = 4;
	int NormalNoteRight = 5;
	int CriticalNote = 6;
	int CriticalNoteLeft = 7;
	int CriticalNoteMiddle = 8;
	int CriticalNoteRight = 9;
	int HoldNote = 10;
	int HoldNoteLeft = 11;
	int HoldNoteMiddle = 12;
	int HoldNoteRight = 13;
	int ScratchNote = 14;
	int ScratchNoteLeft = 15;
	int ScratchNoteMiddle = 16;
	int ScratchNoteRight = 17;
	int ScratchArrow = 18;
	int Hold = 19;
	int Scratch = 20;
	int StageBackground = 21;
	int TouchFeedback = 22;
	int TouchTick = 23;
	int TouchScratchTick = 24;
	int SyncLine = 25;
	int HiddenLine = 26;
	int JudgePerfectPlus = 27;
	int JudgePerfect = 28;
	int JudgeGreat = 29;
	int JudgeGood = 30;
	int JudgeBad = 31;
	int JudgeMiss = 32;
	int JudgeAuto = 33;
	int JudgeFast = 34;
	int JudgeSlow = 35;
	int GridYellow = 36;
	int SplitLine_1 = 37;
	int SplitLineTrans1_1 = 38;
	int SplitLineTrans2_1 = 39;
	int SplitLine_10010 = 40;
	int SplitLineTrans1_10010 = 41;
	int SplitLineTrans2_10010 = 42;
	int SplitLine_10020 = 43;
	int SplitLineTrans1_10020 = 44;
	int SplitLineTrans2_10020 = 45;
	int SplitLine_10030 = 46;
	int SplitLineTrans1_10030 = 47;
	int SplitLineTrans2_10030 = 48;
	int SplitLine_10040 = 49;
	int SplitLineTrans1_10040 = 50;
	int SplitLineTrans2_10040 = 51;
	int SplitLine_10050 = 52;
	int SplitLineTrans1_10050 = 53;
	int SplitLineTrans2_10050 = 54;
	int SplitLine_10060 = 55;
	int SplitLineTrans1_10060 = 56;
	int SplitLineTrans2_10060 = 57;
	int SplitLine_10070 = 58;
	int SplitLineTrans1_10070 = 59;
	int SplitLineTrans2_10070 = 60;
	int SplitLine_1010 = 61;
	int SplitLineTrans1_1010 = 62;
	int SplitLineTrans2_1010 = 63;
	int SplitLine_10100 = 64;
	int SplitLineTrans1_10100 = 65;
	int SplitLineTrans2_10100 = 66;
	int SplitLine_10110 = 67;
	int SplitLineTrans1_10110 = 68;
	int SplitLineTrans2_10110 = 69;
	int SplitLine_10120 = 70;
	int SplitLineTrans1_10120 = 71;
	int SplitLineTrans2_10120 = 72;
	int SplitLine_10130 = 73;
	int SplitLineTrans1_10130 = 74;
	int SplitLineTrans2_10130 = 75;
	int SplitLine_10140 = 76;
	int SplitLineTrans1_10140 = 77;
	int SplitLineTrans2_10140 = 78;
	int SplitLine_10150 = 79;
	int SplitLineTrans1_10150 = 80;
	int SplitLineTrans2_10150 = 81;
	int SplitLine_10160 = 82;
	int SplitLineTrans1_10160 = 83;
	int SplitLineTrans2_10160 = 84;
	int SplitLine_10161 = 85;
	int SplitLineTrans1_10161 = 86;
	int SplitLineTrans2_10161 = 87;
	int SplitLine_10162 = 88;
	int SplitLineTrans1_10162 = 89;
	int SplitLineTrans2_10162 = 90;
	int SplitLine_10170 = 91;
	int SplitLineTrans1_10170 = 92;
	int SplitLineTrans2_10170 = 93;
	int SplitLine_10180 = 94;
	int SplitLineTrans1_10180 = 95;
	int SplitLineTrans2_10180 = 96;
	int SplitLine_10190 = 97;
	int SplitLineTrans1_10190 = 98;
	int SplitLineTrans2_10190 = 99;
	int SplitLine_10191 = 100;
	int SplitLineTrans1_10191 = 101;
	int SplitLineTrans2_10191 = 102;
	int SplitLine_1020 = 103;
	int SplitLineTrans1_1020 = 104;
	int SplitLineTrans2_1020 = 105;
	int SplitLine_10200 = 106;
	int SplitLineTrans1_10200 = 107;
	int SplitLineTrans2_10200 = 108;
	int SplitLine_10220 = 109;
	int SplitLineTrans1_10220 = 110;
	int SplitLineTrans2_10220 = 111;
	int SplitLine_10230 = 112;
	int SplitLineTrans1_10230 = 113;
	int SplitLineTrans2_10230 = 114;
	int SplitLine_10240 = 115;
	int SplitLineTrans1_10240 = 116;
	int SplitLineTrans2_10240 = 117;
	int SplitLine_10250 = 118;
	int SplitLineTrans1_10250 = 119;
	int SplitLineTrans2_10250 = 120;
	int SplitLine_10260 = 121;
	int SplitLineTrans1_10260 = 122;
	int SplitLineTrans2_10260 = 123;
	int SplitLine_10270 = 124;
	int SplitLineTrans1_10270 = 125;
	int SplitLineTrans2_10270 = 126;
	int SplitLine_10280 = 127;
	int SplitLineTrans1_10280 = 128;
	int SplitLineTrans2_10280 = 129;
	int SplitLine_10290 = 130;
	int SplitLineTrans1_10290 = 131;
	int SplitLineTrans2_10290 = 132;
	int SplitLine_1030 = 133;
	int SplitLineTrans1_1030 = 134;
	int SplitLineTrans2_1030 = 135;
	int SplitLine_10300 = 136;
	int SplitLineTrans1_10300 = 137;
	int SplitLineTrans2_10300 = 138;
	int SplitLine_10310 = 139;
	int SplitLineTrans1_10310 = 140;
	int SplitLineTrans2_10310 = 141;
	int SplitLine_10320 = 142;
	int SplitLineTrans1_10320 = 143;
	int SplitLineTrans2_10320 = 144;
	int SplitLine_10321_1 = 145;
	int SplitLineTrans1_10321_1 = 146;
	int SplitLineTrans2_10321_1 = 147;
	int SplitLine_10321_2 = 148;
	int SplitLineTrans1_10321_2 = 149;
	int SplitLineTrans2_10321_2 = 150;
	int SplitLine_10321_3 = 151;
	int SplitLineTrans1_10321_3 = 152;
	int SplitLineTrans2_10321_3 = 153;
	int SplitLine_10321_4 = 154;
	int SplitLineTrans1_10321_4 = 155;
	int SplitLineTrans2_10321_4 = 156;
	int SplitLine_10321_5 = 157;
	int SplitLineTrans1_10321_5 = 158;
	int SplitLineTrans2_10321_5 = 159;
	int SplitLine_10322_1 = 160;
	int SplitLineTrans1_10322_1 = 161;
	int SplitLineTrans2_10322_1 = 162;
	int SplitLine_10322_2 = 163;
	int SplitLineTrans1_10322_2 = 164;
	int SplitLineTrans2_10322_2 = 165;
	int SplitLine_10322_3 = 166;
	int SplitLineTrans1_10322_3 = 167;
	int SplitLineTrans2_10322_3 = 168;
	int SplitLine_10322_4 = 169;
	int SplitLineTrans1_10322_4 = 170;
	int SplitLineTrans2_10322_4 = 171;
	int SplitLine_10322_5 = 172;
	int SplitLineTrans1_10322_5 = 173;
	int SplitLineTrans2_10322_5 = 174;
	int SplitLine_10323_1 = 175;
	int SplitLineTrans1_10323_1 = 176;
	int SplitLineTrans2_10323_1 = 177;
	int SplitLine_10323_2 = 178;
	int SplitLineTrans1_10323_2 = 179;
	int SplitLineTrans2_10323_2 = 180;
	int SplitLine_10323_3 = 181;
	int SplitLineTrans1_10323_3 = 182;
	int SplitLineTrans2_10323_3 = 183;
	int SplitLine_10323_4 = 184;
	int SplitLineTrans1_10323_4 = 185;
	int SplitLineTrans2_10323_4 = 186;
	int SplitLine_10323_5 = 187;
	int SplitLineTrans1_10323_5 = 188;
	int SplitLineTrans2_10323_5 = 189;
	int SplitLine_10324_1 = 190;
	int SplitLineTrans1_10324_1 = 191;
	int SplitLineTrans2_10324_1 = 192;
	int SplitLine_10324_2 = 193;
	int SplitLineTrans1_10324_2 = 194;
	int SplitLineTrans2_10324_2 = 195;
	int SplitLine_10324_3 = 196;
	int SplitLineTrans1_10324_3 = 197;
	int SplitLineTrans2_10324_3 = 198;
	int SplitLine_10325_1 = 199;
	int SplitLineTrans1_10325_1 = 200;
	int SplitLineTrans2_10325_1 = 201;
	int SplitLine_10325_2 = 202;
	int SplitLineTrans1_10325_2 = 203;
	int SplitLineTrans2_10325_2 = 204;
	int SplitLine_10325_3 = 205;
	int SplitLineTrans1_10325_3 = 206;
	int SplitLineTrans2_10325_3 = 207;
	int SplitLine_10325_4 = 208;
	int SplitLineTrans1_10325_4 = 209;
	int SplitLineTrans2_10325_4 = 210;
	int SplitLine_10326_1 = 211;
	int SplitLineTrans1_10326_1 = 212;
	int SplitLineTrans2_10326_1 = 213;
	int SplitLine_10326_2 = 214;
	int SplitLineTrans1_10326_2 = 215;
	int SplitLineTrans2_10326_2 = 216;
	int SplitLine_10326_3 = 217;
	int SplitLineTrans1_10326_3 = 218;
	int SplitLineTrans2_10326_3 = 219;
	int SplitLine_10326_4 = 220;
	int SplitLineTrans1_10326_4 = 221;
	int SplitLineTrans2_10326_4 = 222;
	int SplitLine_10326_5 = 223;
	int SplitLineTrans1_10326_5 = 224;
	int SplitLineTrans2_10326_5 = 225;
	int SplitLine_10327_1 = 226;
	int SplitLineTrans1_10327_1 = 227;
	int SplitLineTrans2_10327_1 = 228;
	int SplitLine_10327_2 = 229;
	int SplitLineTrans1_10327_2 = 230;
	int SplitLineTrans2_10327_2 = 231;
	int SplitLine_10327_3 = 232;
	int SplitLineTrans1_10327_3 = 233;
	int SplitLineTrans2_10327_3 = 234;
	int SplitLine_10327_4 = 235;
	int SplitLineTrans1_10327_4 = 236;
	int SplitLineTrans2_10327_4 = 237;
	int SplitLine_10328_1 = 238;
	int SplitLineTrans1_10328_1 = 239;
	int SplitLineTrans2_10328_1 = 240;
	int SplitLine_10328_2 = 241;
	int SplitLineTrans1_10328_2 = 242;
	int SplitLineTrans2_10328_2 = 243;
	int SplitLine_10328_3 = 244;
	int SplitLineTrans1_10328_3 = 245;
	int SplitLineTrans2_10328_3 = 246;
	int SplitLine_10328_4 = 247;
	int SplitLineTrans1_10328_4 = 248;
	int SplitLineTrans2_10328_4 = 249;
	int SplitLine_10328_5 = 250;
	int SplitLineTrans1_10328_5 = 251;
	int SplitLineTrans2_10328_5 = 252;
	int SplitLine_10330 = 253;
	int SplitLineTrans1_10330 = 254;
	int SplitLineTrans2_10330 = 255;
	int SplitLine_10340 = 256;
	int SplitLineTrans1_10340 = 257;
	int SplitLineTrans2_10340 = 258;
	int SplitLine_10350 = 259;
	int SplitLineTrans1_10350 = 260;
	int SplitLineTrans2_10350 = 261;
	int SplitLine_10360 = 262;
	int SplitLineTrans1_10360 = 263;
	int SplitLineTrans2_10360 = 264;
	int SplitLine_10361 = 265;
	int SplitLineTrans1_10361 = 266;
	int SplitLineTrans2_10361 = 267;
	int SplitLine_10370 = 268;
	int SplitLineTrans1_10370 = 269;
	int SplitLineTrans2_10370 = 270;
	int SplitLine_10380 = 271;
	int SplitLineTrans1_10380 = 272;
	int SplitLineTrans2_10380 = 273;
	int SplitLine_10390 = 274;
	int SplitLineTrans1_10390 = 275;
	int SplitLineTrans2_10390 = 276;
	int SplitLine_10391 = 277;
	int SplitLineTrans1_10391 = 278;
	int SplitLineTrans2_10391 = 279;
	int SplitLine_10392 = 280;
	int SplitLineTrans1_10392 = 281;
	int SplitLineTrans2_10392 = 282;
	int SplitLine_10393 = 283;
	int SplitLineTrans1_10393 = 284;
	int SplitLineTrans2_10393 = 285;
	int SplitLine_1040 = 286;
	int SplitLineTrans1_1040 = 287;
	int SplitLineTrans2_1040 = 288;
	int SplitLine_10400 = 289;
	int SplitLineTrans1_10400 = 290;
	int SplitLineTrans2_10400 = 291;
	int SplitLine_10410 = 292;
	int SplitLineTrans1_10410 = 293;
	int SplitLineTrans2_10410 = 294;
	int SplitLine_10420 = 295;
	int SplitLineTrans1_10420 = 296;
	int SplitLineTrans2_10420 = 297;
	int SplitLine_10430 = 298;
	int SplitLineTrans1_10430 = 299;
	int SplitLineTrans2_10430 = 300;
	int SplitLine_10440 = 301;
	int SplitLineTrans1_10440 = 302;
	int SplitLineTrans2_10440 = 303;
	int SplitLine_10450 = 304;
	int SplitLineTrans1_10450 = 305;
	int SplitLineTrans2_10450 = 306;
	int SplitLine_10460 = 307;
	int SplitLineTrans1_10460 = 308;
	int SplitLineTrans2_10460 = 309;
	int SplitLine_10461 = 310;
	int SplitLineTrans1_10461 = 311;
	int SplitLineTrans2_10461 = 312;
	int SplitLine_10470 = 313;
	int SplitLineTrans1_10470 = 314;
	int SplitLineTrans2_10470 = 315;
	int SplitLine_10480 = 316;
	int SplitLineTrans1_10480 = 317;
	int SplitLineTrans2_10480 = 318;
	int SplitLine_10481_1 = 319;
	int SplitLineTrans1_10481_1 = 320;
	int SplitLineTrans2_10481_1 = 321;
	int SplitLine_10481_2 = 322;
	int SplitLineTrans1_10481_2 = 323;
	int SplitLineTrans2_10481_2 = 324;
	int SplitLine_10481_3 = 325;
	int SplitLineTrans1_10481_3 = 326;
	int SplitLineTrans2_10481_3 = 327;
	int SplitLine_10482 = 328;
	int SplitLineTrans1_10482 = 329;
	int SplitLineTrans2_10482 = 330;
	int SplitLine_10490 = 331;
	int SplitLineTrans1_10490 = 332;
	int SplitLineTrans2_10490 = 333;
	int SplitLine_1050 = 334;
	int SplitLineTrans1_1050 = 335;
	int SplitLineTrans2_1050 = 336;
	int SplitLine_10500 = 337;
	int SplitLineTrans1_10500 = 338;
	int SplitLineTrans2_10500 = 339;
	int SplitLine_10510_1 = 340;
	int SplitLineTrans1_10510_1 = 341;
	int SplitLineTrans2_10510_1 = 342;
	int SplitLine_10510_2 = 343;
	int SplitLineTrans1_10510_2 = 344;
	int SplitLineTrans2_10510_2 = 345;
	int SplitLine_10510_3 = 346;
	int SplitLineTrans1_10510_3 = 347;
	int SplitLineTrans2_10510_3 = 348;
	int SplitLine_10511_1 = 349;
	int SplitLineTrans1_10511_1 = 350;
	int SplitLineTrans2_10511_1 = 351;
	int SplitLine_10511_2 = 352;
	int SplitLineTrans1_10511_2 = 353;
	int SplitLineTrans2_10511_2 = 354;
	int SplitLine_10511_3 = 355;
	int SplitLineTrans1_10511_3 = 356;
	int SplitLineTrans2_10511_3 = 357;
	int SplitLine_10512_1 = 358;
	int SplitLineTrans1_10512_1 = 359;
	int SplitLineTrans2_10512_1 = 360;
	int SplitLine_10512_2 = 361;
	int SplitLineTrans1_10512_2 = 362;
	int SplitLineTrans2_10512_2 = 363;
	int SplitLine_10513_1 = 364;
	int SplitLineTrans1_10513_1 = 365;
	int SplitLineTrans2_10513_1 = 366;
	int SplitLine_10513_2 = 367;
	int SplitLineTrans1_10513_2 = 368;
	int SplitLineTrans2_10513_2 = 369;
	int SplitLine_10514_1 = 370;
	int SplitLineTrans1_10514_1 = 371;
	int SplitLineTrans2_10514_1 = 372;
	int SplitLine_10514_2 = 373;
	int SplitLineTrans1_10514_2 = 374;
	int SplitLineTrans2_10514_2 = 375;
	int SplitLine_10514_3 = 376;
	int SplitLineTrans1_10514_3 = 377;
	int SplitLineTrans2_10514_3 = 378;
	int SplitLine_10515_1 = 379;
	int SplitLineTrans1_10515_1 = 380;
	int SplitLineTrans2_10515_1 = 381;
	int SplitLine_10515_2 = 382;
	int SplitLineTrans1_10515_2 = 383;
	int SplitLineTrans2_10515_2 = 384;
	int SplitLine_10515_3 = 385;
	int SplitLineTrans1_10515_3 = 386;
	int SplitLineTrans2_10515_3 = 387;
	int SplitLine_10516_1 = 388;
	int SplitLineTrans1_10516_1 = 389;
	int SplitLineTrans2_10516_1 = 390;
	int SplitLine_10516_2 = 391;
	int SplitLineTrans1_10516_2 = 392;
	int SplitLineTrans2_10516_2 = 393;
	int SplitLine_10516_3 = 394;
	int SplitLineTrans1_10516_3 = 395;
	int SplitLineTrans2_10516_3 = 396;
	int SplitLine_10517_1 = 397;
	int SplitLineTrans1_10517_1 = 398;
	int SplitLineTrans2_10517_1 = 399;
	int SplitLine_10517_2 = 400;
	int SplitLineTrans1_10517_2 = 401;
	int SplitLineTrans2_10517_2 = 402;
	int SplitLine_10517_3 = 403;
	int SplitLineTrans1_10517_3 = 404;
	int SplitLineTrans2_10517_3 = 405;
	int SplitLine_10518_1 = 406;
	int SplitLineTrans1_10518_1 = 407;
	int SplitLineTrans2_10518_1 = 408;
	int SplitLine_10518_2 = 409;
	int SplitLineTrans1_10518_2 = 410;
	int SplitLineTrans2_10518_2 = 411;
	int SplitLine_10518_3 = 412;
	int SplitLineTrans1_10518_3 = 413;
	int SplitLineTrans2_10518_3 = 414;
	int SplitLine_10518_4 = 415;
	int SplitLineTrans1_10518_4 = 416;
	int SplitLineTrans2_10518_4 = 417;
	int SplitLine_10518_5 = 418;
	int SplitLineTrans1_10518_5 = 419;
	int SplitLineTrans2_10518_5 = 420;
	int SplitLine_10519_1 = 421;
	int SplitLineTrans1_10519_1 = 422;
	int SplitLineTrans2_10519_1 = 423;
	int SplitLine_10519_2 = 424;
	int SplitLineTrans1_10519_2 = 425;
	int SplitLineTrans2_10519_2 = 426;
	int SplitLine_10519_3 = 427;
	int SplitLineTrans1_10519_3 = 428;
	int SplitLineTrans2_10519_3 = 429;
	int SplitLine_10519_4 = 430;
	int SplitLineTrans1_10519_4 = 431;
	int SplitLineTrans2_10519_4 = 432;
	int SplitLine_10519_5 = 433;
	int SplitLineTrans1_10519_5 = 434;
	int SplitLineTrans2_10519_5 = 435;
	int SplitLine_10530 = 436;
	int SplitLineTrans1_10530 = 437;
	int SplitLineTrans2_10530 = 438;
	int SplitLine_10540 = 439;
	int SplitLineTrans1_10540 = 440;
	int SplitLineTrans2_10540 = 441;
	int SplitLine_10550 = 442;
	int SplitLineTrans1_10550 = 443;
	int SplitLineTrans2_10550 = 444;
	int SplitLine_10560 = 445;
	int SplitLineTrans1_10560 = 446;
	int SplitLineTrans2_10560 = 447;
	int SplitLine_10570 = 448;
	int SplitLineTrans1_10570 = 449;
	int SplitLineTrans2_10570 = 450;
	int SplitLine_10580 = 451;
	int SplitLineTrans1_10580 = 452;
	int SplitLineTrans2_10580 = 453;
	int SplitLine_10590 = 454;
	int SplitLineTrans1_10590 = 455;
	int SplitLineTrans2_10590 = 456;
	int SplitLine_10600 = 457;
	int SplitLineTrans1_10600 = 458;
	int SplitLineTrans2_10600 = 459;
	int SplitLine_1060a = 460;
	int SplitLineTrans1_1060a = 461;
	int SplitLineTrans2_1060a = 462;
	int SplitLine_1060b = 463;
	int SplitLineTrans1_1060b = 464;
	int SplitLineTrans2_1060b = 465;
	int SplitLine_10610 = 466;
	int SplitLineTrans1_10610 = 467;
	int SplitLineTrans2_10610 = 468;
	int SplitLine_10620 = 469;
	int SplitLineTrans1_10620 = 470;
	int SplitLineTrans2_10620 = 471;
	int SplitLine_10630 = 472;
	int SplitLineTrans1_10630 = 473;
	int SplitLineTrans2_10630 = 474;
	int SplitLine_10631 = 475;
	int SplitLineTrans1_10631 = 476;
	int SplitLineTrans2_10631 = 477;
	int SplitLine_10640 = 478;
	int SplitLineTrans1_10640 = 479;
	int SplitLineTrans2_10640 = 480;
	int SplitLine_10650 = 481;
	int SplitLineTrans1_10650 = 482;
	int SplitLineTrans2_10650 = 483;
	int SplitLine_10660 = 484;
	int SplitLineTrans1_10660 = 485;
	int SplitLineTrans2_10660 = 486;
	int SplitLine_10670 = 487;
	int SplitLineTrans1_10670 = 488;
	int SplitLineTrans2_10670 = 489;
	int SplitLine_10680 = 490;
	int SplitLineTrans1_10680 = 491;
	int SplitLineTrans2_10680 = 492;
	int SplitLine_10690 = 493;
	int SplitLineTrans1_10690 = 494;
	int SplitLineTrans2_10690 = 495;
	int SplitLine_10710 = 496;
	int SplitLineTrans1_10710 = 497;
	int SplitLineTrans2_10710 = 498;
	int SplitLine_10720 = 499;
	int SplitLineTrans1_10720 = 500;
	int SplitLineTrans2_10720 = 501;
	int SplitLine_2 = 502;
	int SplitLineTrans1_2 = 503;
	int SplitLineTrans2_2 = 504;
	int SplitLine_2010 = 505;
	int SplitLineTrans1_2010 = 506;
	int SplitLineTrans2_2010 = 507;
	int SplitLine_2020 = 508;
	int SplitLineTrans1_2020 = 509;
	int SplitLineTrans2_2020 = 510;
	int SplitLine_2030 = 511;
	int SplitLineTrans1_2030 = 512;
	int SplitLineTrans2_2030 = 513;
	int SplitLine_2040a = 514;
	int SplitLineTrans1_2040a = 515;
	int SplitLineTrans2_2040a = 516;
	int SplitLine_2040b = 517;
	int SplitLineTrans1_2040b = 518;
	int SplitLineTrans2_2040b = 519;
	int SplitLine_2050 = 520;
	int SplitLineTrans1_2050 = 521;
	int SplitLineTrans2_2050 = 522;
	int SplitLine_3 = 523;
	int SplitLineTrans1_3 = 524;
	int SplitLineTrans2_3 = 525;
	int SplitLine_3010 = 526;
	int SplitLineTrans1_3010 = 527;
	int SplitLineTrans2_3010 = 528;
	int SplitLine_3020 = 529;
	int SplitLineTrans1_3020 = 530;
	int SplitLineTrans2_3020 = 531;
	int SplitLine_3030 = 532;
	int SplitLineTrans1_3030 = 533;
	int SplitLineTrans2_3030 = 534;
	int SplitLine_3040 = 535;
	int SplitLineTrans1_3040 = 536;
	int SplitLineTrans2_3040 = 537;
	int SplitLine_3050 = 538;
	int SplitLineTrans1_3050 = 539;
	int SplitLineTrans2_3050 = 540;
	int SplitLine_4 = 541;
	int SplitLineTrans1_4 = 542;
	int SplitLineTrans2_4 = 543;
	int SplitLine_4010 = 544;
	int SplitLineTrans1_4010 = 545;
	int SplitLineTrans2_4010 = 546;
	int SplitLine_4020 = 547;
	int SplitLineTrans1_4020 = 548;
	int SplitLineTrans2_4020 = 549;
	int SplitLine_4030 = 550;
	int SplitLineTrans1_4030 = 551;
	int SplitLineTrans2_4030 = 552;
	int SplitLine_4040 = 553;
	int SplitLineTrans1_4040 = 554;
	int SplitLineTrans2_4040 = 555;
	int SplitLine_4050 = 556;
	int SplitLineTrans1_4050 = 557;
	int SplitLineTrans2_4050 = 558;
	int SplitLine_5 = 559;
	int SplitLineTrans1_5 = 560;
	int SplitLineTrans2_5 = 561;
	int SplitLine_6 = 562;
	int SplitLineTrans1_6 = 563;
	int SplitLineTrans2_6 = 564;
	int SplitLine_7 = 565;
	int SplitLineTrans1_7 = 566;
	int SplitLineTrans2_7 = 567;
	int SplitLine_8 = 568;
	int SplitLineTrans1_8 = 569;
	int SplitLineTrans2_8 = 570;
	int SplitLine_9 = 571;
	int SplitLineTrans1_9 = 572;
	int SplitLineTrans2_9 = 573;
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
	{"Sirius Judgment Perfect+", Sprites.JudgePerfectPlus},
	{"Sirius Judgment Perfect", Sprites.JudgePerfect},
	{"Sirius Judgment Great", Sprites.JudgeGreat},
	{"Sirius Judgment Good", Sprites.JudgeGood},
	{"Sirius Judgment Bad", Sprites.JudgeBad},
	{"Sirius Judgment Miss", Sprites.JudgeMiss},
	{"Sirius Judgment Auto", Sprites.JudgeAuto},
	{"Sirius Judgment Fast", Sprites.JudgeFast},
	{"Sirius Judgment Slow", Sprites.JudgeSlow},
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
