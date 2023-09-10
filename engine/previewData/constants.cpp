using namespace std;

const var interfaceGap = 0.05;                      // 组件间距
const var stageWidth = 0.7;                         // 单个舞台宽度
const var stageHeight = 2.0;                        // 单个舞台高度
const var stageFullWidth = stageWidth + 0.3;        // 单个舞台占有宽度
const var stageTimelineWidth = stageWidth + 0.2;    // 时间线宽度
const var stageTimeLength = 2.0;                    // 单个舞台容纳时间
const var noteHeight = 0.04;                        // 按键高度
const var adjustDistance = 0.002;                   // 按键微调距离
const var noteCountDistance = 10;                   // 按键计数长度
const var tickWidth = 0.03;                         // tick 宽度
const var tickHeight = 0.045;						// tick 高度
const var syncLineHeight = 0.003; 					// 同步线高度
const var arrowWidth = 0.03;						// 箭头宽度
const var arrowHeight = 0.06;						// 箭头高度
const var arrowPercent = 1.6;						// 箭头占比
const var splitLineAnimationStart = 0.75;           // 分裂线起始动画长度, basic: 0.7595
const var splitLineAnimationEnd = 0.20;             // 分裂线结束动画长度, basic: 0.7595
Variable<PreviewDataId> duration;                   // 谱面时长
Variable<PreviewDataId> noteCount;                  // note 数量
Variable<EntitySharedMemoryId> noteId;              // note 编号
Array<TemporaryMemoryId> splitLineMemory = Array<TemporaryMemoryId>(16);