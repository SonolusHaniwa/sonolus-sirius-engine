<?php
// $api_address = "http://192.168.0.156:8080";
// $cookie = "sessionId=B51B2C6FA3D13C96D5DD3237CE56A24D";
// $api_address = "http://192.168.0.102:8080";
// $cookie = "sessionId=A76B2BFEB76741032E1639DED8F14BFD";
$api_address = "http://8.130.81.127:8000";
$cookie = "sessionId=B8AE6FEC103475FBB7B76FC27CCD1AD5";
// $api_address = "http://127.0.0.1:8080";
// $cookie = "sessionId=9ABBAB4E60A4358391DA5A47A7D7D94A";
$engine_id = "1";

$uploader = $api_address . "/uploader";
$create_bg = $api_address . "/sonolus/backgrounds/create";
$create_lv = $api_address . "/sonolus/levels/create";
$info_bg = $api_address . "/sonolus/backgrounds/";
$info_lv = $api_address . "/sonolus/levels/";
$ResourceList = array();

function read_file($path, $decode = true) {
    $fp = fopen($path, "r");
    if (!$decode) return fread($fp, filesize($path));
    return json_decode(fread($fp, filesize($path)), true);
}

function posturl($url, $data, $cookie, $decode = true){
    $curl = curl_init();
    curl_setopt($curl, CURLOPT_URL, $url);
    curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, FALSE);
    curl_setopt($curl, CURLOPT_SSL_VERIFYHOST,FALSE);
    curl_setopt($curl, CURLOPT_POST, 1);
    curl_setopt($curl, CURLOPT_POSTFIELDS, $data);
    curl_setopt($curl, CURLOPT_COOKIE, $cookie);
    curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
    $output = curl_exec($curl);
    if ($output == "") {
        echo "Failed to load \"$url\"! Retrying...\n";
        return posturl($url, $data, $cookie, $decode);
    }
    curl_close($curl);
    if (!$decode) return $output;
    return json_decode($output, true);
}

function upload_file($path) {
    global $uploader;
    global $cookie;
    global $ResourceList;
    if (array_key_exists($path, $ResourceList)) return $ResourceList[$path];
    $e = base64_encode(read_file($path, false));
    $hash = posturl($uploader, "file=" . $e, $cookie)["hash"];
    if ($hash == "") {
        echo "Failed to upload \"$path\"! Retrying...\n";
        return upload_file($path);
    }
    $ResourceList[$path] = $hash;
    return $hash;
}

$level = [ "normal", "hard", "extra", "stella", "oliver" ];

$artists = [
    "鳳ここな", "静香", "カトリナ・グリーベル", "新妻八恵", "柳場ぱんだ", "流石知冴",  // 0 - 5
    "連尺野初魅", "烏森大黒", "舎人仁花子", "萬容", "筆島しぐれ",                   // 6 - 10
    "千寿暦", "ラモーナ・ウォルフ", "王雪", "リリヤ・クルトベイ", "与那国緋花里",      // 11 - 15
    "千寿いろは", "白丸美兎", "阿伎留カミラ", "猫足蕾", "本巣叶羽",                 // 16 - 20
    "柊望有"
];

$data = [
    1 => [
        "name" => "ワナビスタ！",
        "artists" => [0, 1, 2, 3, 4, 5],
        "level" => [7, 13, 20, 25, 35]
    ],
    2 => [
        "name" => "トゥ・オブ・アス",
        "artists" => [0, 1],
        "level" => [7, 16, 21, 26, 35]
    ],
    3 => [
        "name" => "勿忘唄",
        "artists" => [0, 1],
        "level" => [6, 14, 19, 25, 34]
    ],
    4 => [
        "name" => "夢見月夜",
        "artists" => [3],
        "level" => [6, 13, 20, 24, 33]
    ],
    5 => [
        "name" => "悠久月華",
        "artists" => [12],
        "level" => [5, 12, 17, 23, 31]
    ],
    6 => [
        "name" => "ダイヤモンドの誓い",
        "artists" => [0],
        "level" => [6, 14, 20, 25, 33]
    ],
    7 => [
        "name" => "魔法のラストノート",
        "artists" => [3],
        "level" => [10, 17, 23, 28, 38]
    ],
    8 => [
        "name" => "New Nostalgic Friend",
        "artists" => [0, 3],
        "level" => [6, 13, 20, 24, 32]
    ],
    9 => [
        "name" => "Drawing World",
        "artists" => [16, 17, 20],
        "level" => [8, 14, 22, 25, 33]
    ],
    10 => [
        "name" => "名もなき恋人よ",
        "artists" => [4, 5],
        "level" => [5, 12, 18, 23, 32]
    ],
    11 => [
        "name" => "Etoile",
        "artists" => [3],
        "level" => [5, 11, 17, 23, 36]
    ],
    12 => [
        "name" => "Masquerade",
        "artists" => [0, 3],
        "level" => [8, 15, 22, 27, 36]
    ],
    13 => [
        "name" => "Farewell song",
        "artists" => [3],
        "level" => [6, 13, 19, 24, 33]
    ],
    15 => [
        "name" => "Decide",
        "artists" => [2],
        "level" => [6, 13, 18, 24, 32]
    ],
    16 => [
        "name" => "ウタカタメロディ",
        "artists" => [12, 13],
        "level" => [8, 14, 22, 26, 34]
    ],
    17 => [
        "name" => "シリウスの輝きのように",
        "artists" => [0, 1, 2, 3, 4, 5],
        "level" => [11, 18, 25, 28, 36]
    ],
    "17_2" => [
        "name" => "シリウスの輝きのように(full ver.)",
        "artists" => [0, 1, 2, 3, 4, 5],
        "level" => [11, 18, 25, -1, -1]
    ],
    19 => [
        "name" => "Faith in Expression",
        "artists" => [6, 7, 8, 9, 10],
        "level" => [11, 18, 23, 27, 37]
    ],
    "19_2" => [
        "name" => "Faith in Expression(full ver.)",
        "artists" => [6, 7, 8, 9, 10],
        "level" => [11, 18, 23, -1, -1]
    ],
    21 => [
        "name" => "プラネタリウム・レヴュー",
        "artists" => [11, 12, 13, 14, 15],
        "level" => [8, 15, 22, 27, 34]
    ],
    "21_2" => [
        "name" => "プラネタリウム・レヴュー(full ver.)",
        "artists" => [11, 12, 13, 14, 15],
        "level" => [8, 15, 22, 27, -1]
    ],
    23 => [
        "name" => "デアエ・エクス・マキナ！",
        "artists" => [16, 17, 18, 19, 20],
        "level" => [9, 16, 23, 27, 37]
    ],
    "23_2" => [
        "name" => "デアエ・エクス・マキナ！(full ver.)",
        "artists" => [16, 17, 18, 19, 20],
        "level" => [9, 16, 23, -1, -1]
    ],
    25 => [
        "name" => "Binary Star",
        "artists" => [0, 1],
        "level" => [9, 16, 21, 26, 35]
    ],
    26 => [
        "name" => "暁星アストレーション",
        "artists" => [2, 12],
        "level" => [11, 17, 25, 28, 35]
    ],
    27 => [
        "name" => "情熱リベレイション",
        "artists" => [11, 12],
        "level" => [10, 16, 24, 27, 36]
    ],
    29 => [
        "name" => "幾億の星の空で",
        "artists" => [5, 21],
        "level" => [6, 13, 19, 23, 35]
    ],
    30 => [
        "name" => "純粋と奔放",
        "artists" => [6, 8],
        "level" => [7, 14, 20, 25, 33]
    ],
    31 => [
        "name" => "心という名の不可解",
        "artists" => [11],
        "level" => [9, 17, 24, 27, 37]
    ],
    33 => [
        "name" => "Snow halation",
        "artists" => [0, 1, 2, 3, 4, 5],
        "level" => [8, 15, 21, 26, 34]
    ],
    34 => [
        "name" => "フォニイ",
        "artists" => [8],
        "level" => [10, 16, 23, 27, 36]
    ],
    35 => [
        "name" => "チューリングラブ",
        "artists" => [12, 14],
        "level" => [7, 15, 22, 25, 34]
    ],
    37 => [
        "name" => "Shiny Smily Story",
        "artists" => [0, 1, 2, 8, 9],
        "level" => [7, 16, 22, 26, 34]
    ],
    38 => [
        "name" => "変わらないもの",
        "artists" => [2],
        "level" => [5, 11, 18, 23, 31]
    ],
    39 => [
        "name" => "Realize",
        "artists" => [4],
        "level" => [12, 18, 25, 29, 39]
    ],
    40 => [
        "name" => "魔法少女とチョコレゐト",
        "artists" => [20],
        "level" => [11, 17, 24, 27, 37]
    ],
    41 => [
        "name" => "怪物",
        "artists" => [10],
        "level" => [9, 16, 21, 26, 34]
    ],
    42 => [
        "name" => "六兆年と一夜物語",
        "artists" => [12],
        "level" => [12, 18, 26, 29, 38]
    ],
    43 => [
        "name" => "名前のない怪物",
        "artists" => [19],
        "level" => [7, 15, 22, 26, 35]
    ],
    45 => [
        "name" => "Blondie Revenge Tragedy",
        "artists" => [7],
        "level" => [10, 17, 22, 27, 35]
    ],
    46 => [
        "name" => "Fernweh",
        "artists" => [2],
        "level" => [5, 12, 19, 24, 32]
    ],
    47 => [
        "name" => "サマーバカンス☆アクトレス",
        "artists" => [18, 19],
        "level" => [9, 16, 22, 26, 35]
    ],
    49 => [
        "name" => "パーティー·ジョーク·シンデレラ",
        "artists" => [3],
        "level" => [7, 14, 20, 24, 33]
    ],
    50 => [
        "name" => "てぃだんちゅ MEETS てぃんがーら！",
        "artists" => [15],
        "level" => [8, 15, 21, 26, 35]
    ],
    55 => [
        "name" => "ANIMA",
        "artists" => [8],
        "level" => [10, 15, 23, 28, 36]
    ],
    87 => [
        "name" => "可愛くてごめん",
        "artists" => [18],
        "level" => [-1, -1, -1, -1, -1]
    ]
];

function calcBackground($title) {
    global $api_address;
    global $cookie;
    $html = posturl($api_address . "/levels/create", "", $cookie, false);
    preg_match_all('/<option[^>]*value="(.*?)"[^>]*>(.*?)<\/option>/si', $html, $match);
    for ($i = 0; $i < count($match[0]); $i++) {
        if (strpos($match[2][$i], $title) === false) continue;
        return $match[1][$i];
    }
    return 0;
}

foreach($data as $k => $v) {
    $bg_name = "sirius-$k";
    // Upload Background
    if (array_key_exists("code", posturl($info_bg . $bg_name, "", "")) || true) {
        $title = $v["name"];
        $subtitle = "";
        for ($i = 0; $i < count($v["artists"]); $i++) {
            $subtitle .= $artists[$v["artists"][$i]];
            if ($i != count($v["artists"]) - 1) $subtitle .= "、";
        } $author = "ワールドダイスター 夢のステラリウム";
        $thumbnail = upload_file("./$k/cover.png");
        $data = upload_file("./BackgroundData");
        $image = upload_file("./$k/background.png");
        $configuration = upload_file("./BackgroundConfiguration");
        $localization = 0; $description = "Version: 1.0.0";
        $jsonarr = posturl($create_bg, 
        "name=$bg_name&title=$title&subtitle=$subtitle&author=$author&thumbnail=$thumbnail" .
        "&data=$data&image=$image&configuration=$configuration&localization=$localization&description=$description", $cookie);
        echo "Background $bg_name: " . json_encode($jsonarr) . "\n";
    }

    // Upload Level
    for ($i = 0; $i < 5; $i++) {
        if ($v["level"][$i] == -1) continue;
        $name = "sirius-$k-" . $level[$i];
        $rating = $v["level"][$i];
        $title = $v["name"];
        $artist = "";
        for ($j = 0; $j < count($v["artists"]); $j++) {
            $artist .= $artists[$v["artists"][$j]];
            if ($j != count($v["artists"]) - 1) $artist .= "、";
        } $author = "ワールドダイスター 夢のステラリウム";
        $engine = $engine_id;
        $skin = 0;
        $background = calcBackground($title);
        $effect = 0;
        $particle = 0;
        $cover = upload_file("./$k/cover.png");
        $bgm = upload_file("./$k/music.mp3");
        $preview = upload_file("./$k/musicpreview.mp3");
        exec("./main ./$k/" . ($i + 1) . ".txt ./$k/music_config.txt ./$k/" . ($i + 1));
        $data = upload_file("./$k/" . ($i + 1));
        $localization = 0;
        $description = "";
        $jsonarr = posturl($create_lv, 
        "name=$name&rating=$rating&title=$title&artists=$artist&author=$author&engine=$engine" .
        "&skin=$skin&background=$background&effect=$effect&particle=$particle&cover=$cover&bgm=$bgm&data=$data&preview=$preview&localization=$localization&description=$description"
        , $cookie);
        echo "Level $name: " . json_encode($jsonarr) . "\n";
    }
}

?>