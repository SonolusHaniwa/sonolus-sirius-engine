using namespace std;

class Buckets {
    public:
	
	int NormalNote = 0;
	int CriticalNote = 1;
	int FlickNote = 2;
	int HoldStart = 3;
	int CriticalHoldStart = 4;
	// int NormalHoldEighth = 5;
	int HoldEnd = 5;
	int Sound = 6;
	int ScratchHoldStart = 7;
	int ScratchCriticalHoldStart = 8;
	// int ScratchHoldEighth = 10;
	int ScratchHoldEnd = 9;
	int ScratchSound = 10;
}Buckets;

auto bucket = defineBuckets<class Buckets>({
	{
		sprites: {
			{
				id: Sprites.NormalNote,
				x: 0,
				y: 0,
				w: 2.0,
				h: 1.0,
				rotation: 270
			}
		},
		unit: UnitText.Millisecond
	}, {
		sprites: {
			{
				id: Sprites.CriticalNote,
				x: 0,
				y: 0,
				w: 2.0,
				h: 1.0,
				rotation: 270
			}
		},
		unit: UnitText.Millisecond
	}, {
		sprites: {
			{
				id: Sprites.ScratchNote,
				x: -0.35,
				y: 0,
				w: 2.0,
				h: 1.0,
				rotation: 270
			},	{
				id: Sprites.ScratchArrow,
				x: 0.25,
				y: 0.8,
				w: 0.4,
				h: 1.2,
				rotation: 270
			}, {
				id: Sprites.ScratchArrow,
				x: 0.25,
				y: 0.6,
				w: 0.4,
				h: 1.2,
				rotation: 270
			}, {
				id: Sprites.ScratchArrow,
				x: 0.25,
				y: 0.4,
				w: 0.4, 
				h: 1.2,
				rotation: 270
			},	{
				id: Sprites.ScratchArrow,
				x: 0.25,
				y: 0.2,
				w: 0.4,
				h: 1.2,
				rotation: 270
			},	{
				id: Sprites.ScratchArrow,
				x: 0.25,
				y: -0.8,
				w: 0.4,
				h: 1.2,
				rotation: 90
			}, {
				id: Sprites.ScratchArrow,
				x: 0.25,
				y: -0.6,
				w: 0.4,
				h: 1.2,
				rotation: 90
			}, {
				id: Sprites.ScratchArrow,
				x: 0.25,
				y: -0.4,
				w: 0.4, 
				h: 1.2,
				rotation: 90
			}, {
				id: Sprites.ScratchArrow,
				x: 0.25,
				y: -0.2,
				w: 0.4, 
				h: 1.2,
				rotation: 90
			}
		}, 
		unit: UnitText.Millisecond
	}, {
		sprites: {
			{
				id: Sprites.Hold,
				x: 0.25,
				y: 0.0,
				w: 1.8,
				h: 6.0,
				rotation: 270
			}, {
				id: Sprites.HoldNote,
				x: -2.75,
				y: 0.0,
				w: 2.0,
				h: 1.0,
				rotation: 270
			}
		},
		unit: UnitText.Millisecond
	}, {
		sprites: {
			{
				id: Sprites.Hold,
				x: 0.25,
				y: 0.0,
				w: 1.8,
				h: 6.0,
				rotation: 270
			}, {
				id: Sprites.CriticalNote,
				x: -2.75,
				y: 0.0,
				w: 2.0,
				h: 1.0,
				rotation: 270
			}
		},
		unit: UnitText.Millisecond
	}, {
	// 	sprites: {
	// 		{
	// 			id: Sprites.Hold,
	// 			x: 0.0,
	// 			y: 0.0,
	// 			w: 1.8,
	// 			h: 6.0,
	// 			rotation: 270
	// 		}
	// 	}, 
	// 	unit: UnitText.Millisecond
	// }, {
		sprites: {
			{
				id: Sprites.Hold,
				x: -0.25,
				y: 0.0,
				w: 1.8,
				h: 6.0,
				rotation: 270
			}, {
				id: Sprites.HoldNote,
				x: 2.75,
				y: 0.0,
				w: 2.0,
				h: 1.0,
				rotation: 270
			}
		},
		unit: UnitText.Millisecond
	}, {
		sprites: {
			{
				id: Sprites.Hold,
				x: 0.0,
				y: 0.0,
				w: 1.8,
				h: 6.0,
				rotation: 270
			}, {
				id: Sprites.TouchTick,
				x: 0.0,
				y: 0.0,
				w: 1.0,
				h: 1.0,
				rotation: 270
			}
		},
		unit: UnitText.Millisecond
	}, {
		sprites: {
			{
				id: Sprites.Scratch,
				x: 0.25,
				y: 0.0,
				w: 1.8,
				h: 6.0,
				rotation: 270
			}, {
				id: Sprites.ScratchNote,
				x: -2.75,
				y: 0.0,
				w: 2.0,
				h: 1.0,
				rotation: 270
			}
		},
		unit: UnitText.Millisecond
	}, {
		sprites: {
			{
				id: Sprites.Scratch,
				x: 0.25,
				y: 0.0,
				w: 1.8,
				h: 6.0,
				rotation: 270
			}, {
				id: Sprites.CriticalNote,
				x: -2.75,
				y: 0.0,
				w: 2.0,
				h: 1.0,
				rotation: 270
			}
		},
		unit: UnitText.Millisecond
	}, {
	// 	sprites: {
	// 		{
	// 			id: Sprites.Scratch,
	// 			x: 0.0,
	// 			y: 0.0,
	// 			w: 1.8,
	// 			h: 6.0,
	// 			rotation: 270
	// 		}
	// 	},
	// 	unit: UnitText.Millisecond
	// }, {
		sprites: {
			{
				id: Sprites.Scratch,
				x: -0.6,
				y: 0.0,
				w: 1.8,
				h: 6.0,
				rotation: 270
			}, {
				id: Sprites.ScratchNote,
				x: 2.4,
				y: 0.0,
				w: 2.0,
				h: 1.0,
				rotation: 270
			},	{
				id: Sprites.ScratchArrow,
				x: 3.0,
				y: 0.8,
				w: 0.4,
				h: 1.2,
				rotation: 270
			}, {
				id: Sprites.ScratchArrow,
				x: 3.0,
				y: 0.6,
				w: 0.4,
				h: 1.2,
				rotation: 270
			}, {
				id: Sprites.ScratchArrow,
				x: 3.0,
				y: 0.4,
				w: 0.4, 
				h: 1.2,
				rotation: 270
			},	{
				id: Sprites.ScratchArrow,
				x: 3.0,
				y: 0.2,
				w: 0.4,
				h: 1.2,
				rotation: 270
			},	{
				id: Sprites.ScratchArrow,
				x: 3.0,
				y: -0.8,
				w: 0.4,
				h: 1.2,
				rotation: 90
			}, {
				id: Sprites.ScratchArrow,
				x: 3.0,
				y: -0.6,
				w: 0.4,
				h: 1.2,
				rotation: 90
			}, {
				id: Sprites.ScratchArrow,
				x: 3.0,
				y: -0.4,
				w: 0.4, 
				h: 1.2,
				rotation: 90
			}, {
				id: Sprites.ScratchArrow,
				x: 3.0,
				y: -0.2,
				w: 0.4, 
				h: 1.2,
				rotation: 90
			}
		},
		unit: UnitText.Millisecond
	}, {
		sprites: {
			{
				id: Sprites.Scratch,
				x: 0.0,
				y: 0.0,
				w: 1.8,
				h: 6.0,
				rotation: 270
			}, {
				id: Sprites.TouchScratchTick,
				x: 0.0,
				y: 0.0,
				w: 1.0,
				h: 1.0,
				rotation: 270
			}
		},
		unit: UnitText.Millisecond
	}
});
