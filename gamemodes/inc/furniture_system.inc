//dialogs
#define DIALOG_FURNITURE_MAIN 2996
#define DIALOG_FURNITURE_BUY 2997
#define DIALOG_FURNITURE_EDIT 2998
#define DIALOG_FURNITURE_BUY3 2999
#define DIALOG_FURNITURE_BUY_CONFIRM 3000
#define DIALOG_FURNITURE_EDIT_SELECT 3001
#define DIALOG_FURNITURE_SHOWHIDE_SELECT 3002
#define DIALOG_FURNITURE_DELETE_SELECT 3003

static str[128];

//max limits
#define MAX_FURNITURE 100
#define MAX_OUTDOOR_FURNITURE 5

//validation
#define INVALID_FURNITURE_ID 0

//list of furniture objects
enum fFurnitureObjectList {
	fD_type,
	fD_model,
	fD_name[50],
	fD_price,
	Float:fD_rotX,
	Float:fD_rotY
}

new FurnitureObjectList[][fFurnitureObjectList] = {
	{1, 2274, "Picture Of Flower", 500, 0.0, 0.0},//Decor 0
	{1, 2279, "Picture of Chilliad", 500, 0.0, 0.0},
	{1, 2265, "Picture of Desert", 500, 0.0, 0.0},
	{1, 2268, "Picture of Cat", 500, 0.0, 0.0},
	{1, 2277, "Picture of Snowball", 600, 0.0, 0.0},
	{1, 2263, "Picture of Night City", 650, 0.0, 0.0},
	{1, 2269, "Picture of Lake", 650, 0.0, 0.0},
	{1, 2275, "Picture of Fruit", 600, 0.0, 0.0},
	{1, 2261, "Picture of Bridge", 600, 0.0, 0.0},
	{1, 2264, "Picture of Beach", 600, 0.0, 0.0},
	{1, 2282, "Picture of Sunset", 600, 0.0, 0.0},
	{1, 2255, "Picture of Ass", 600, 0.0, 0.0},
	{1, 2287, "Picture of Boats", 600, 0.0, 0.0},
	{1, 2276, "Picture of Bridges", 600, 0.0, 0.0},
	{1, 2284, "Picture of Church", 600, 0.0, 0.0},
	{1, 2285, "Picture of Map", 600, 0.0, 0.0},
	{1, 2271, "Pic. of something Special", 600, 0.0, 0.0},
	{1, 2273, "Picture of Flowers", 600, 0.0, 0.0},
	{1, 2280, "Picture of River", 600, 0.0, 0.0},
	{1, 2286, "Picture of Ship", 600, 0.0, 0.0},
	{1, 2254, "Picture of Car", 600, 0.0, 0.0},
	{1, 2256, "Picture of Palms", 600, 0.0, 0.0},
	{1, 2257, "Modern Art", 700, 0.0, 0.0},
	{1, 3962, "Modern Art 2", 700, 0.0, -90.0},
	{1, 2587, "Poster1", 200, 0.0, 0.0},
	{1, 2588, "Poster2", 200, 0.0, 0.0},
	{1, 2691, "Poster3", 200, 0.0, 0.0},
	{1, 19825, "Clock", 800, 0.0, 180.0},
	{1, 2828, "Desk Picture Frames", 700, 0.0, 0.0},
	{1, 1736, "Deer's Head", 700, 0.0, 0.0},
	{1, 11733, "Rocking Horse", 800, 0.0, 0.0},
	{1, 1828, "Tiger Rug", 1200, -90.0, 0.0},
	{1, 2841, "Rug 1", 500, 90.0, 0.0},
	{1, 2835, "Rug 2", 500, 90.0, 0.0},
	{1, 2842, "Rug 3", 500, 90.0, 0.0},
	{1, 2847, "Rug 4", 500, 90.0, 0.0},
	{1, 2817, "Rug 5", 500, 90.0, 0.0},
	{1, 2815, "Rug 6", 500, 90.0, 0.0},
	{1, 2833, "Rug 7", 500, 90.0, 0.0},
	{1, 2834, "Rug 8", 500, 90.0, 0.0},
	{1, 2836, "Rug 9", 500, 90.0, 0.0},
	{1, 2818, "Rug 10", 500, 90.0, 0.0},
	{1, 11737, "Doormat", 300, 90.0, 180.0},
	{1, 11712, "Cross", 200, 0.0, 90.0},
	{1, 11710, "Exit Sign", 200, 0.0, 180.0},
	{1, 18664, "Tag Sign 1", 200, 0.0, 180.0},
	{1, 18665, "Tag Sign 2", 200, 0.0, 180.0},
	{1, 18666, "Tag Sign 3", 200, 0.0, 180.0},
	{1, 18667, "Tag Sign 4", 200, 0.0, 180.0},
	{1, 18663, "Tag Sign 5", 200, 0.0, 180.0},
	{1, 18662, "Tag Sign 6", 200, 0.0, 180.0},
	{1, 18661, "Tag Sign 7", 200, 0.0, 180.0},
	{1, 18660, "Tag Sign 8", 200, 0.0, 180.0},
	{1, 18659, "Tag Sign 9", 200, 0.0, 180.0},
	{1, 933, "Cable Roll", 200, 0.0, 0.0},
	{1, 19836, "Blood Splatter", 200, 90.0, 180.0},
	{1, 2068, "Cargo Net", 2500, 0.0, 0.0},
	{1, 2945, "Netting", 800, 0.0, 0.0},
	{1, 948, "Pot plant", 300, 0.0, 0.0},
	{1, 949, "Pot plant2", 300, 0.0, 0.0},
	{1, 950, "Pot plant4", 300, 0.0, 0.0},
	{1, 2010, "Plant", 300, 0.0, 0.0},
	{1, 2011, "Plant 2",300, 0.0, 0.0},
	{1, 2176, "Vase", 300, 0.0, 0.0},
	{1, 2194, "Cactus", 300, 0.0, 0.0},
	{1, 2195, "Bush", 300, 0.0, 0.0},
	{1, 2240, "Pot plant", 300, 0.0, 0.0},
	{1, 2241, "Pot plant", 300, 0.0, 0.0},
	{1, 2242, "Pot plant", 300, 0.0, 0.0},
	{1, 2243, "Pot plant", 300, 0.0, 0.0},
	{1, 2244, "Pot plant", 300, 0.0, 0.0},
	{1, 2245, "Pot plant", 300, 0.0, 0.0},
	{1, 2246, "Vase", 500, 0.0, 0.0},
	{1, 2247, "Vase 1", 500, 0.0, 0.0},
	{1, 2248, "Pot", 300, 0.0, 0.0},
	{1, 2249, "Vase 2", 600, 0.0, 0.0},
	{1, 2250, "Vase 3", 600, 0.0, 0.0},
	{1, 2251, "Vase 4", 600, 0.0, 0.0},
	{1, 14705, "Vase 5", 600, 0.0, 0.0},
	{1, 2252, "Pot plant", 100, 0.0, 0.0},
	{1, 2253, "Pot plant", 100, 0.0, 0.0},
	{1, 2868, "Candle", 100, 0.0, 0.0},
	{1, 2869, "Candles", 400, 0.0, 0.0},
	{1, 3802, "Hanging plant1", 200, 0.0, 0.0},
	{1, 3809, "Hanging plant2", 200, 0.0, 0.0},
	{1, 3810, "Hanging plant3", 200, 0.0, 0.0},
	{1, 14804, "Pot plant1", 200, 0.0, 0.0},
	{1, 14834, "Pot plant2", 200, 0.0, 0.0},
	{1, 2067, "Filing Cabinet", 1000, 0.0, 0.0},//Office 90
	{1, 2609, "Filing Cabinet 2", 1000, 0.0, 0.0},
	{1, 2065, "Filing Cabinet 3", 1000, 0.0, 0.0},
	{1, 2066, "Filing Cabinet 4", 1000, 0.0, 0.0},
	{1, 2610, "Filing Cabinet 5", 1000, 0.0, 0.0},
	{1, 2167, "Office Cupboard", 1100, 180.0, 180.0},
	{1, 2161, "Office Bookshelf", 1300, 180.0, 180.0},
	{1, 2163, "Office Wall Cupboard", 1250, 180.0, 180.0},
	{1, 2737, "Blue Notice Board", 1200, 0.0, 0.0},
	{1, 2191, "Filing Case", 1300, 180.0, 180.0},
	{1, 2162, "Office Bookshelf", 1300, 180.0, 180.0},
	{1, 2608, "Office Bookshelf 2", 1400, 180.0, 180.0},
	{1, 2199, "Office BookShelf 3", 1400, 180.0, 180.0},
	{1, 2164, "Office Bookshelf 3", 1400, 180.0, 180.0},
	{1, 2204, "Brown Office Cabinet", 1600, 180.0, 180.0},
	{1, 2208, "Ellipse Office Unit", 1700, 0.0, 0.0},
	{1, 14455, "Bookshelves", 2300, 0.0, 0.0},
	{1, 2202, "Large Printer", 1000, 0.0, 0.0},
	{1, 19805, "Whiteboard", 1200, 0.0, 0.0},
	{1, 2616, "Noticeboard", 1000, 0.0, 0.0},
	{1, 3077, "Big Chalkboard", 1000, 0.0, 0.0},
	{1, 19999, "Office Chair", 900, 180.0, 180.0},
	{1, 2356, "Office Chair 2", 900, 0.0, 0.0},
	{1, 1671, "Office Chair 3", 900, 180.0, 180.0},
	{1, 1714, "Office Chair 4", 500, 180.0, 180.0},
	{1, 1663, "Office Chair 5", 500, 180.0, 180.0},
	{1, 1715, "Office Chair 6", 600, 180.0, 180.0},
	{1, 1721, "Office Chair 7", 600, 0.0, 0.0},
	{1, 2310, "Office Chair 8", 500, 0.0, 0.0},
	{1, 2308, "Desk 1", 900, 0.0, 180.0},
	{1, 2185, "Desk 2", 900, 0.0, 0.0},
	{1, 2184, "Desk 3", 900, 0.0, 0.0},
	{1, 2206, "Desk 4", 900, 0.0, 0.0},
	{1, 2008, "Desk 5", 900, 0.0, 0.0},
	{1, 2207, "Desk 6", 900, 0.0, 0.0},
	{1, 2205, "Desk 7", 900, 0.0, 0.0},
	{1, 1963, "Desk 8", 900, 0.0, 0.0},
	{1, 2174, "Desk 9", 900, 0.0, 180.0},
	{1, 2173, "Desk 10", 900, 0.0, 0.0},
	{1, 2166, "Desk 11", 900, 0.0, 0.0},
	{1, 2165, "Desk 12", 900, 0.0, 0.0},
	{1, 2605, "Desk 13", 900, 0.0, 0.0},
	{1, 2607, "Desk 14", 900, 0.0, 0.0},
	{1, 1999, "Desk 15", 900, 0.0, 0.0},
	{1, 2894, "Opened Book", 500, 0.0, 0.0},//Hobby 134
	{1, 19939, "Rectangle Shelf", 600, 0.0, 0.0},
	{1, 19938, "Corner Shelf", 400, 0.0, 0.0},
	{1, 1961, "Record Green", 200, 0.0, 0.0},
	{1, 1962, "Record Purple", 200, 0.0, 0.0},
	{1, 2114, "Basket Ball", 300, 0.0, 0.0},
	{1, 3496, "Basket ball hoop", 1000, 0.0, 0.0},
	{1, 3497, "Basket ball stand", 1000, 0.0, 0.0},
	{1, 1974, "Golf Ball", 150, 0.0, 0.0},
	{1, 3017, "Blueprints", 500, 0.0, 0.0},
	{1, 3111, "Blueprints 1", 500, 0.0, 0.0},
	{1, 2046, "Hobby Cupboard", 1500, 0.0, 0.0},
	{1, 14820, "DJ Stuff", 2100, 0.0, 0.0},
	{1, 1742, "Hobby Bookshelf", 1600, 0.0, 0.0},
	{1, 941, "Hobby Work Bench", 1400, 0.0, 0.0},
	{1, 14556, "Open Cupboard", 1500, 0.0, 0.0},
	{1, 2855, "Stack of Magazines", 100, 0.0, 0.0},
	{1, 2854, "Pile of Books", 200, 0.0, 0.0},
	{1, 2853, "Pile of Books 2", 200, 0.0, 0.0},
	{1, 2852, "Pile of Magazines", 200, 0.0, 0.0},
	{1, 2816, "Opened Magazines", 200, 0.0, 0.0},
	{1, 19921, "Toolbox", 600, 0.0, 0.0},
	{1, 19878, "Skateboard", 400, 0.0, 0.0},
	{1, 2630, "Exercise Bike", 1200, 0.0, 0.0},
	{1, 2629, "Gym Bench", 1400, 0.0, 0.0},
	{1, 2628, "Leg Press", 1400, 0.0, 0.0},
	{1, 2627, "Treadmill", 1400, 0.0, 0.0},
	{1, 2916, "Dumbbell", 500, 0.0, 0.0},
	{1, 2913, "Bar", 1000, 0.0, 0.0},
	{1, 1985, "Boxing bag", 800, 0.0, 0.0},
	{1, 19815, "Workshop Tools", 800, 0.0, 0.0},
	{1, 19621, "Oil Can", 600, 0.0, 0.0},
	{1, 19897, "Packet of Smokes", 200, 0.0, 0.0},
	{1, 19609, "Drum Kit", 2000, 0.0, 0.0},
	{1, 19317, "Electric Guitar", 1000, 0.0, 0.0},
	{1, 19610, "Microphone", 1100, 0.0, 0.0},
	{1, 19611, "Microphone Stand", 500, 0.0, 0.0},
	{1, 19613, "Guitar Amp", 700, 0.0, 0.0},
	{1, 19624, "Travelling Suitcase", 400, 0.0, 0.0},
	{1, 11729, "Locker", 800, 0.0, 0.0},
	{1, 11738, "Medical Box", 200, 0.0, 0.0},
	{1, 11736, "Medical Pack", 200, 0.0, 0.0},
	{1, 11745, "Big Black Dufflebag", 200, 0.0, 0.0},
	{1, 1954, "Turn Table", 500, 0.0, 0.0},
	{1, 2964, "Pool Table", 700, 0.0, 0.0},
	{1, 14651, "Pool Table Set", 1000, 0.0, 0.0},
	{1, 2965, "Pool Triangle", 300, 0.0, 0.0},
	{1, 3003, "Pool White Ball", 200, 0.0, 0.0},
	{1, 3002, "Pool Orange Ball", 200, 0.0, 0.0},
	{1, 3106, "Pool 8 Ball", 200, 0.0, 0.0},
	{1, 3004, "Pool Cue", 400, 0.0, 0.0},
	{1, 19918, "Magic Box", 400, 0.0, 0.0},
	{1, 11725, "Black Fireplace", 2500, 0.0, 0.0},//Lounge 186
	{1, 11724, "Large Stone Fireplace", 5000, 0.0, 0.0},
	{1, 19632, "Wooden Logs", 800, 0.0, 0.0},
	{1, 2313, "TV Cabinet", 600, 0.0, 0.0},
	{1, 2311, "TV Cabinet 2", 600, 0.0, 0.0},
	{1, 2078, "China Cabinet", 800, 0.0, 0.0},
	{1, 2083, "Glass Coffee Table", 800, 0.0, 0.0},
	{1, 1821, "Wooden Trolley", 800, 0.0, 0.0},
	{1, 2082, "Dark Square Coffee", 1000, 0.0, 0.0},
	{1, 1823, "Dark Coffee Table", 900, 0.0, 0.0},
	{1, 1822, "Round Coffee Table", 1200, 0.0, 0.0},
	{1, 1815, "Round Wood Coffee", 800, 0.0, 0.0},
	{1, 2236, "Rectangle Coffee Tab", 1100, 0.0, 0.0},
	{1, 1814, "Wooden Coffee Table", 900, 0.0, 0.0},
	{1, 2081, "Semi-circle Coffee", 800, 0.0, 0.0},
	{1, 1819, "Round Coffee Table", 900, 0.0, 0.0},
	{1, 2235, "Old Coffee Table", 1000, 0.0, 0.0},
	{1, 2084, "Glass China Cabinet", 1000, 0.0, 0.0},
	{1, 1759, "Weaved Old Chair", 1400, 180.0, 180.0},
	{1, 1765, "Beige Sofa Chair", 1600, 180.0, 180.0},
	{1, 1758, "Dark Sofa Chair", 1600, 180.0, 180.0},
	{1, 1755, "Blue Sofa Chair", 1600, 180.0, 180.0},
	{1, 1769, "Blue Wood Sofa Chair", 1600, 180.0, 180.0},
	{1, 1762, "Basic Sofa Chair", 1600, 180.0, 180.0},
	{1, 1767, "Basic Sofa Chair 2", 1600, 180.0, 180.0},
	{1, 11717, "Love Sofa", 2100, 180.0, 180.0},
	{1, 1707, "Future Sofa", 2200, 0.0, 0.0},
	{1, 1764, "Beige Sofa", 2200, 180.0, 180.0},
	{1, 1763, "Weaved Sofa", 2200, 180.0, 180.0},
	{1, 1712, "Old Worn Sofa", 2200, 180.0, 180.0},
	{1, 1702, "Brown Sofa", 2200, 180.0, 180.0},
	{1, 1706, "Chip Sofa", 2200, 180.0, 180.0},
	{1, 1768, "Blue Sofa", 2200, 180.0, 180.0},
	{1, 1766, "Budget Sofa", 2200, 180.0, 180.0},
	{1, 1757, "Budget Dark Sofa", 2200, 180.0, 180.0},
	{1, 1761, "Budget Dark Sofa 2", 2200, 180.0, 180.0},
	{1, 1713, "Business Sofa", 2200, 180.0, 180.0},
	{1, 1703, "Black Posh Sofa", 2200, 180.0, 180.0},
	{1, 1760, "Blue Sofa 2", 2200, 180.0, 180.0},
	{1, 1756, "Dark Budget Sofa", 2200, 180.0, 180.0},
	{1, 14491, "Sofa & Table Set", 3000, 0.0, 0.0},
	{1, 1710, "Large Old Sofa", 2300, 180.0, 180.0},
	{1, 14493, "Two Sofa Set", 2800, 0.0, 0.0},
	{1, 2293, "Ottomat", 600, 0.0, 0.0},
	{1, 1735, "Chair", 700, 180.0, 180.0},
	{1, 11734, "Rocking Chair", 700, 180.0, 180.0},
	{1, 2096, "Rocking Chair 2", 500, 180.0, 180.0},
	{1, 2306, "Cabinet", 800, 180.0, 180.0},//Bedroom
	{1, 2021, "Pink Drawers", 1200, 180.0, 180.0},
	{1, 2020, "Pink Drawers 2", 1400, 180.0, 180.0},
	{1, 1740, "Wooden Bedside", 1000, 180.0, 180.0},
	{1, 2095, "Bedside Drawers", 1100, 180.0, 180.0},
	{1, 1417, "Ugly Wardroom", 1000, 180.0, 180.0},
	{1, 2323, "Wooden Drawers", 1000, 180.0, 180.0},
	{1, 1743, "Medium Cabinet", 1000, 180.0, 180.0},
	{1, 2145, "Clothes Cabinet", 1000, 180.0, 180.0},
	{1, 2025, "Posh Wardroom", 1200, 180.0, 180.0},
	{1, 2329, "Wooden Wardroom", 1200, 180.0, 180.0},
	{1, 2569, "White Dresser", 1200, 180.0, 180.0},
	{1, 2574, "Dresser & Table", 1800, 180.0, 180.0},
	{1, 2570, "Dresser & Utils", 1500, 180.0, 180.0},
	{1, 2576, "Wooden Dressers", 1700, 180.0, 180.0},
	{1, 2568, "Dark Table & Lamps", 1400, 180.0, 180.0},
	{1, 1812, "Foldup Bed", 800, 180.0, 180.0},
	{1, 1771, "Mattress & Base Bed", 1000, 180.0, 180.0},
	{1, 1796, "Single Bed", 1100, 180.0, 180.0},
	{1, 11720, "King Single Bed", 1700, 180.0, 180.0},
	{1, 2302, "Queen Bed", 1800, 180.0, 180.0},
	{1, 1794, "Queen Bed 2", 1700, 180.0, 180.0},
	{1, 14866, "Queen Bed 3", 1900, 180.0, 180.0},
	{1, 1700, "Queen Bed 4", 1800, 180.0, 180.0},
	{1, 2301, "Queen Bed 5", 2000, 180.0, 180.0},
	{1, 2090, "Queen Bed 6", 1800, 180.0, 180.0},
	{1, 2299, "Queen Bed 7", 2000, 180.0, 180.0},
	{1, 1797, "Queen Bed 8", 1900, 180.0, 180.0},
	{1, 1701, "Queen Bed 9", 1800, 180.0, 180.0},
	{1, 1745, "Queen Bed 10", 1900, 180.0, 180.0},
	{1, 1795, "Queen Bed 11", 1400, 180.0, 180.0},
	{1, 1798, "Queen Bed 12", 1500, 180.0, 180.0},
	{1, 1799, "Queen Bed 13", 1700, 180.0, 180.0},
	{1, 1801, "Queen Bed 14", 1500, 180.0, 180.0},
	{1, 1802, "Queen Bed 15", 1600, 180.0, 180.0},
	{1, 1803, "Queen Bed 16", 1800, 180.0, 180.0},
	{1, 1793, "Queen Mattresses", 1200, 180.0, 180.0},
	{1, 14880, "Queen Mattresses 2", 1200, 180.0, 180.0},
	{1, 14861, "Queen Mattresses 3", 1200, 180.0, 180.0},
	{1, 2575, "Bedroom Set, Bed", 2000, 180.0, 180.0},
	{1, 11731, "Heart Bed", 2000, 180.0, 180.0},
	{1, 2399, "Rack of Clothes", 200, 0.0, 0.0},
	{1, 11735, "Boot", 200, 0.0, 0.0},
	{1, 2689, "Shirt", 400, 0.0, 0.0},
	{1, 2704, "Shirt2", 400, 0.0, 0.0},
	{1, 2706, "Shirt3", 400, 0.0, 0.0},
	{1, 2694, "Shoebox", 200, 0.0, 0.0},
	{1, 2003, "Safe1", 500, 180.0, 180.0},
	{1, 2004, "Safe2", 500, 180.0, 180.0},
	{1, 2005, "Safe3", 500, 180.0, 180.0},
	{1, 19931, "Dark Counter", 1000, 180.0, 180.0},//Kitchen 283
	{1, 19928, "Dark Counter 2", 1000, 180.0, 180.0},
	{1, 19930, "Dark Counter 3", 1000, 180.0, 180.0},
	{1, 19932, "Dark Oven Cabinet", 1000, 180.0, 180.0},
	{1, 19935, "Dark Cupboard", 1000, 180.0, 180.0},
	{1, 19925, "Dark Corner Counter", 1000, 180.0, 180.0},
	{1, 19936, "Dark Cut Counter", 1000, 180.0, 180.0},
	{1, 19937, "Dark Cupboard 2", 1000, 180.0, 180.0},
	{1, 2089, "Dark Cupboard 3", 1000, 180.0, 180.0},
	{1, 19927, "Dark Sink", 1000, 180.0, 180.0},
	{1, 19923, "Dark Island", 2500, 180.0, 180.0},
	{1, 19929, "Dark Trip. Counter", 2000, 180.0, 180.0},
	{1, 2139, "Maple Counter", 1200, 180.0, 180.0},
	{1, 2303, "Maple Dishwasher", 1200, 180.0, 180.0},
	{1, 2133, "Steel Counter", 1100, 180.0, 180.0},
	{1, 2134, "Steel Counter 2", 1100, 180.0, 180.0},
	{1, 2341, "Steel Corner Counter", 1100, 180.0, 180.0},
	{1, 2335, "Green Counter", 1200, 180.0, 180.0},
	{1, 2334, "Green Counter 2", 1200, 180.0, 180.0},
	{1, 2338, "Green Corner Counter", 1200,180.0, 180.0},
	{1, 2156, "Green Doub. Counter", 1200, 180.0, 180.0},
	{1, 2157, "Green Doub Counter 2", 1200, 180.0, 180.0},
	{1, 2159, "Green Slot Counter", 1200, 180.0, 180.0},
	{1, 2160, "Green Sink", 1200, 180.0, 180.0},
	{1, 2155, "White Counter", 1300, 180.0, 180.0},
	{1, 2152, "White Long Counter", 1300, 180.0, 180.0},
	{1, 2154, "White Sink", 1300, 180.0, 180.0},
	{1, 2151, "White Top Bot Counter", 1300, 180.0, 180.0},
	{1, 2142, "Black/Wood Counter", 1400, 180.0, 180.0},
	{1, 2148, "Black/Wood Counter 2", 1400, 180.0, 180.0},
	{1, 2148, "Black/Wood Dishwasher", 1400, 180.0, 180.0},
	{1, 2136, "Counter with Sink", 1500, 180.0, 180.0},
	{1, 2013, "Orange Counter Sink", 1400, 180.0, 180.0},
	{1, 2015, "Orange Counter", 1100, 180.0, 180.0},
	{1, 2017, "Orange Oven Counter", 1100, 180.0, 180.0},
	{1, 2018, "Orange Wash Machine", 1100, 180.0, 180.0},
	{1, 2022, "Orange Corner Counter", 1100, 180.0, 180.0},
	{1, 2016, "Orange Draws Counter", 1100, 180.0, 180.0},
	{1, 2019, "Orange Fridge Counter", 1100, 180.0, 180.0},
	{1, 2127, "Kitchenset red", 700, 180.0, 180.0},
	{1, 2128, "Kitchenset red", 700, 180.0, 180.0},
	{1, 2129, "Kitchenset red", 700, 180.0, 180.0},
	{1, 2130, "Kitchenset red", 700, 180.0, 180.0},
	{1, 2092, "Circle Pantry", 1800, 180.0, 180.0},
	{1, 19915, "White Old Stove", 2200, 180.0, 180.0},
	{1, 936, "Work Bench 1", 1500, 180.0, 180.0},
	{1, 937, "Work Bench 2", 1500, 180.0, 180.0},
	{1, 2451, "Work Bench 3", 1500, 180.0, 180.0},
	{1, 2419, "Work Bench 4", 1500, 180.0, 180.0},
	{1, 2418, "Work Bench 5", 1500, 180.0, 180.0},
	{1, 19916, "Fridge", 2100, 180.0, 180.0},
	{1, 2532, "Bar Fridge", 3000, 180.0, 180.0},
	{1, 19933, "Oven", 1400, 180.0, 180.0},
	{1, 1773, "Oven 2", 1000, 180.0, 180.0},
	{1, 1777, "Oven 3", 1200, 180.0, 180.0},
	{1, 2144, "Oven 4", 900, 180.0, 180.0},
	{1, 19924, "Extraction Hood", 2200, 0.0, 0.0},
	{1, 2150, "Sink", 800, 180.0, 180.0},
	{1, 2427, "Sprunk Machine", 1800, 180.0, 180.0},
	{1, 11743, "Coffee Machine", 1900,180.0, 180.0},
	{1, 1808, "Water Dispenser", 1900, 180.0, 180.0},
	{1, 2832, "Dirty Dishes", 200, 0.0, 0.0},
	{1, 2850, "Dirty Dishes 2", 200, 0.0, 0.0},
	{1, 19993, "Bowl", 200, 0.0, 0.0},
	{1, 11744, "Plate", 200, 0.0, 0.0},
	{1, 2822, "Plate Set", 300, 0.0, 0.0},
	{1, 2829, "Plate Set 2", 300, 0.0, 0.0},
	{1, 2864, "Bowl Set", 300, 0.0, 0.0},
	{1, 19835, "Coffee Cup", 200, 0.0, 0.0},
	{1, 2437, "Cup Pile", 200, 0.0, 0.0},
	{1, 11718, "Sauce Pan 1", 200, 0.0, 0.0},
	{1, 11719, "Sauce Pan 2", 200, 0.0, 0.0},
	{1, 19585, "Sauce Pan 3", 200, 0.0, 0.0},
	{1, 19584, "Sauce Pan 4", 200, 0.0, 0.0},
	{1, 19581, "Fry pan", 200, 0.0, 0.0},
	{1, 19586, "Spatula", 200, 0.0, 0.0},
	{1, 19583, "Sharp Knife", 200, 0.0, 0.0},
	{1, 11715, "Fork", 200, 0.0, 0.0},
	{1, 11716, "Butter Knife", 200, 0.0, 0.0},
	{1, 19582, "Meat", 200, 0.0, 0.0},
	{1, 19882, "Cooked Meat", 200, 0.0, 0.0},
	{1, 19580, "Pizza", 200, 0.0, 0.0},
	{1, 19571, "Pizza Box", 200, 0.0, 0.0},
	{1, 2881, "Slice of Pizza", 200, 0.0, 0.0},
	{1, 19576, "Green Apple", 200, 0.0, 0.0},
	{1, 19575, "Red Apple", 200, 0.0, 0.0},
	{1, 19578, "Banana", 200, 0.0, 0.0},
	{1, 19579, "Loaf of Bread", 200, 0.0, 0.0},
	{1, 19561, "Cereal Box 1", 200, 0.0, 0.0},
	{1, 19562, "Cereal Box 2", 200, 0.0, 0.0},
	{1, 19563, "Orange Juice", 200, 0.0, 0.0},
	{1, 19564, "Apple Juice", 200, 0.0, 0.0},
	{1, 19566, "Fish Fingers", 200, 0.0, 0.0},
	{1, 19567, "Ice Cream", 200, 0.0, 0.0},
	{1, 19570, "Bottle of Milk", 200, 0.0, 0.0},
	{1, 19572, "Box of Beer", 200, 0.0, 0.0},
	{1, 19573, "Bag of Coal", 200, 0.0, 0.0},
	{1, 19574, "Orange", 200, 0.0, 0.0},
	{1, 19630, "Fish", 200, 0.0, 0.0},
	{1, 19818, "Wine Glass", 200, 0.0, 0.0},
	{1, 19820, "Wine Bottle 1", 200, 0.0, 0.0},
	{1, 19821, "Wine Bottle 2", 200, 0.0, 0.0},
	{1, 19822, "Wine Bottle 3", 200, 0.0, 0.0},
	{1, 19824, "Wine Bottle 4", 200, 0.0, 0.0},
	{1, 19883, "Piece of Bread", 200, 0.0, 0.0},
	{1, 19587, "Plastic Pallet", 200, 0.0, 0.0},
	{1, 11722, "Ketchup", 200, 0.0, 0.0},
	{1, 11723, "Mustard", 200, 0.0, 0.0},
	{1, 11741, "Cake", 200, 0.0, 0.0},
	{1, 11742, "Slice of Cake", 200, 0.0, 0.0},
	{1, 11706, "Trashcan", 500, 0.0, 0.0},
	{1, 1486, "Bottle 1", 100, 0.0, 0.0},
	{1, 1487, "Bottle 2", 100, 0.0, 0.0},
	{1, 1509, "Bottle 3", 100, 0.0, 0.0},
	{1, 1520, "Bottle 4", 100, 0.0, 0.0},
	{1, 1543, "Bottle 5", 100, 0.0, 0.0},
	{1, 1544, "Bottle 6", 100, 0.0, 0.0},
	{1, 1664, "Wine", 100, 0.0, 0.0},
	{1, 1668, "Wine 2", 100, 0.0, 0.0},
	{1, 1669, "Wine 3", 100, 0.0, 0.0},
	{1, 1670, "Wine 4", 100, 0.0, 0.0},
	{1, 1665, "Ashtray", 80, 0.0, 0.0},
	{1, 1546, "Cup", 90, 0.0, 0.0},
	{1, 1950, "Bottle 7", 100, 0.0, 0.0},
	{1, 2829, "Dishes", 80, 0.0, 0.0},
	{1, 2822, "Dishes2", 80, 0.0, 0.0},
	{1, 2830, "Dishes3", 80, 0.0, 0.0},
	{1, 2831, "Dishes4", 80, 0.0, 0.0},
	{1, 2832, "Dishes5", 80, 0.0, 0.0},
	{1, 2848, "Dishes6", 80, 0.0, 0.0},
	{1, 2849, "Dishes7", 80, 0.0, 0.0},
	{1, 2856, "Milk", 80, 0.0, 0.0},
	{1, 2857,"Empty Pizza",  50, 0.0, 0.0},
	{1, 2858, "Empty Chinese", 50, 0.0, 0.0},
	{1, 2860, "Pizza", 200, 0.0, 0.0},
	{1, 2803, "Meat", 400, 0.0, 0.0},
	{1, 1820, "Round Dining Table", 1600, 0.0, 0.0},//Dining 419
	{1, 2112, "Medium Wood Table", 1600, 0.0, 0.0},
	{1, 2080, "Ellipse Wood Table", 1600, 0.0, 0.0},
	{1, 2110, "Basic Dining Table", 1600, 0.0, 0.0},
	{1, 1737, "Basic Dining Table 2", 1600, 0.0, 0.0},
	{1, 1770, "Basic Dining Table 3", 1600, 0.0, 0.0},
	{1, 2032, "Basic Dining Table 4", 1600, 0.0, 0.0},
	{1, 2118, "Maple Dining Table", 1800, 0.0, 0.0},
	{1, 2030, "Round Maple Dining", 2000, 0.0, 0.0},
	{1, 15037, "Table with Chair & TV", 2100, 0.0, 0.0},
	{1, 19997, "Small Table", 500, 0.0, 0.0},
	{1, 1516, "Small Table 2", 500, 0.0, 0.0},
	{1, 2764, "Cloth Table", 800, 0.0, 0.0},
	{1, 1811, "Dining Chair 1", 400, 0.0, 0.0},
	{1, 2636, "Dining Chair 2", 400, 0.0, 0.0},
	{1, 2121, "Dining Chair 3", 400, 0.0, 0.0},
	{1, 2776, "Dining Chair 4", 400, 0.0, 0.0},
	{1, 2120, "Dining Chair 5", 400, 0.0, 0.0},
	{1, 1739, "Dining Chair 6", 400, 0.0, 0.0},
	{1, 2807, "Dining Chair 7", 400, 0.0, 0.0},
	{1, 1720, "Dining Chair 8", 400, 0.0, 0.0},
	{1, 2123, "Dining Chair 9", 400, 0.0, 0.0},
	{1, 2124, "Dining Chair 10", 400, 0.0, 0.0},
	{1, 19996, "Dining Chair 11", 400, 0.0, 0.0},
	{1, 1716, "Stool", 400, 0.0, 0.0},
	{1, 2350, "Stool 2", 400, 0.0, 0.0},
	{1, 2125, "Stool 3", 400, 0.0, 0.0},
	{1, 1805, "Stool 4", 400, 0.0, 0.0},
	{1, 2802, "Table & Chairs", 800, 0.0, 0.0},
	{1, 2801, "Table Top 1", 500, 0.0, 0.0},
	{1, 2800, "Table Top 2", 500, 0.0, 0.0},
	{1, 1670, "Table Top 3", 500, 0.0, 0.0},
	{1, 11732, "Heart Bath Tub", 4000, 0.0, 0.0},//Bathroom 451
	{1, 2526, "Bath Tub", 1100, 0.0, 0.0},
	{1, 2516, "Bath Tub 2", 1200, 0.0, 0.0},
	{1, 2519, "Bath Tub 3", 1300, 0.0, 0.0},
	{1, 2522, "Bath Tub 4", 1300, 0.0, 0.0},
	{1, 14494, "Shower Bath", 800, 0.0, 0.0},
	{1, 2527, "Shower", 800, 0.0, 0.0},
	{1, 2517, "Shower 2", 800, 0.0, 0.0},
	{1, 2528, "Toilet", 500, 0.0, 0.0},
	{1, 2521, "Toilet 2", 400, 0.0, 0.0},
	{1, 2525, "Toilet 3", 500, 0.0, 0.0},
	{1, 19873, "Toilet Paper", 200, 0.0, 0.0},
	{1, 2515, "Sink", 600, 0.0, 0.0},
	{1, 2518, "Sink 2", 800, 0.0, 0.0},
	{1, 2523, "Sink 3", 1000, 0.0, 0.0},
	{1, 2524, "Sink 4", 800, 0.0, 0.0},
	{1, 2739, "Sink 5", 900, 0.0, 0.0},
	{1, 11707, "Towel Rack", 500, 0.0, 0.0},
	{1, 19874, "Bar of Soap", 50, 0.0, 0.0},
	{1, 2742, "Hand dryer", 300, 0.0, 0.0},
	{1, 2750, "Hair dryer", 300, 0.0, 0.0},
	{1, 2752, "Hair product", 200, 0.0, 0.0},
	{1, 2751, "Hair product2", 200, 0.0, 0.0},
	{1, 2741, "Soap dispenser", 700, 0.0, 0.0},
	{1, 11709, "Sink", 1200, 0.0, 0.0},//Laundry 475
	{1, 1208, "Washer", 1500, 0.0, 0.0},
	{1, 19622, "Broom", 200, 0.0, 0.0},
	{1, 1778, "Mop & Bucket", 300, 0.0, 0.0},
	{1, 2844, "Clothes 1", 200, 0.0, 0.0},
	{1, 2845, "Clothes 2", 200, 0.0, 0.0},
	{1, 2846, "Clothes 3", 200, 0.0, 0.0},
	{1, 2819, "Clothes 4", 200, 0.0, 0.0},
	{1, 2843, "Clothes 5", 200, 0.0, 0.0},
	{1, 14401, "Benches", 900, 0.0, 0.0},
	{1, 19920, "TV Remote", 200, 0.0, 0.0},//Electronics 485
	{1, 19807, "Telephone", 500, 0.0, 0.0},
	{1, 19808, "Keyboard", 500, 0.0, 0.0},
	{1, 2149, "Microwave", 700, 0.0, 0.0},
	{1, 2421, "Microwave 2", 800, 0.0, 0.0},
	{1, 1719, "Console", 800, 0.0, 0.0},
	{1, 2028, "Console 2", 800, 0.0, 0.0},
	{1, 19830, "Blender", 800, 0.0, 0.0},
	{1, 11705, "Old Telephone", 800, 0.0, 0.0},
	{1, 2102, "Radio", 900, 0.0, 0.0},
	{1, 14772, "Television", 1200, 0.0, 0.0},
	{1, 1790, "Video Player", 800, 0.0, 0.0},
	{1, 1782, "Video Player 2", 800, 0.0, 0.0},
	{1, 1747, "Old Television", 1000, 0.0, 0.0},
	{1, 1748, "Large Television", 1200, 0.0, 0.0},
	{1, 2320, "Large Television 2", 1200, 0.0, 0.0},
	{1, 2190, "Computer", 2100, 0.0, 0.0},
	{1, 1781, "Modern Television", 1400, 0.0, 0.0},
	{1, 2318, "Modern Television 2", 1400, 0.0, 0.0},
	{1, 2101, "Stero Set", 1800, 0.0, 0.0},
	{1, 19614, "Guitar Amp", 1200, 0.0, 0.0},
	{1, 2226, "Funk Stero", 1400, 0.0, 0.0},
	{1, 2322, "Grey Television", 1000, 0.0, 0.0},
	{1, 2595, "TV with Recorder", 1200, 0.0, 0.0},
	{1, 2596, "Wall TV", 1200, 0.0, 0.0},
	{1, 2231, "Speaker", 700, 0.0, 0.0},
	{1, 2225, "Flash Stero", 1000, 0.0, 0.0},
	{1, 2227, "Flash Speaker", 400, 0.0, 0.0},
	{1, 2426, "Pizza Oven", 1200, 0.0, 0.0},
	{1, 2233, "Speaker on Stand", 500, 0.0, 0.0},
	{1, 2103, "Stero", 800, 0.0, 0.0},
	{1, 2312, "Flash Television", 2000, 0.0, 0.0},
	{1, 1786, "Flash Television 2", 2000, 0.0, 0.0},
	{1, 2104, "HI-FI Sound Set", 1700, 0.0, 0.0},
	{1, 2229, "HI-FI Speaker", 500, 0.0, 0.0},
	{1, 2232, "HI-FI Speaker 2", 500, 0.0, 0.0},
	{1, 1717, "Television on Stand", 1000, 0.0, 0.0},
	{1, 11721, "Electric Heater", 800, 0.0, 0.0},
	{1, 1738, "Old Radiator", 500, 0.0, 0.0},
	{1, 2099, "Large Stero", 2200, 0.0, 0.0},
	{1, 14806, "TV & Stero Set", 3000, 0.0, 0.0},
	{1, 14527, "Ceiling Fan", 1200, 0.0, 0.0},
	{1, 19623, "Camera", 800, 0.0, 0.0},
	{1, 19786, "LCD TV Big", 2300, 0.0, 0.0},
	{1, 19787, "LCD TV Medium", 1700, 0.0, 0.0},
	{1, 19893, "Laptop Open", 1200, 0.0, 0.0},
	{1, 19894, "Laptop Closed", 1000, 0.0, 0.0},
	{1, 19273, "Keypad of Security", 800, 0.0, 0.0},
	{1, 1616, "Security Camera", 800, 0.0, 0.0},
	{1, 920, "Generator", 1800, 0.0, 0.0},
	{1, 927, "Electric Wires", 800, 0.0, 0.0},
	{1, 955, "Sprunk Machine", 1400, 0.0, 0.0},
	{1, 956, "Snack Machine", 1500, 0.0, 0.0},
	{1, 2966, "Cellphone1", 100, 0.0, 0.0},
	{1, 2967, "Cellphone2", 100, 0.0, 0.0},
	{1, 3785, "Wall Light", 500, 0.0, 0.0},//Lights 540
	{1, 11727, "Wall Light 2", 500, 0.0, 0.0},
	{1, 2239, "Light Stand", 500, 0.0, 0.0},
	{1, 2107, "Desk Lamp", 500, 0.0, 0.0},
	{1, 2069, "Floor Lamp", 500, 0.0, 0.0},
	{1, 1731, "Wall Lamp", 500, 0.0, 0.0},
	{1, 3801, "Wall Lamp 2", 500, 0.0, 0.0},
	{1, 1734, "Ceiling Light", 500, 0.0, 0.0},
	{1, 2073, "Ceiling Light 2", 500, 0.0, 0.0},
	{1, 2074, "Ceiling Light 3", 500, 0.0, 0.0},
	{1, 2076, "Ceiling Light 4", 500, 0.0, 0.0},
	{1, 2026, "Ceiling Light 5", 500, 0.0, 0.0},
	{1, 1893, "Ceiling Light 6", 500, 0.0, 0.0},
	{1, 16779, "Ceiling Light & Fan", 500, 0.0, 0.0},
	{1, 2196, "Desk Lamp", 500, 0.0, 0.0},
	{1, 2238, "Lava Lamp", 500, 0.0, 0.0},
	{1, 2726, "Red Lamp", 500, 0.0, 0.0},
	{1, 3534, "Red Lamp 2", 500, 0.0, 0.0},
	{1, 19806, "Chandelier", 1200, 0.0, 0.0},
	{1, 11726, "Chandelier 2", 1200, 0.0, 0.0},
	{1, 19827, "Light Switch", 200, 0.0, 0.0},
	{1, 1280, "Wooden Bench", 500, 0.0, 0.0},//Outdoor 561
	{1, 1430, "Trash Bin", 500, 0.0, 0.0},
	{1, 1344, "Dumpster", 500, 0.0, 0.0},
	{1, 1439, "Dumpster 2", 500, 0.0, 0.0},
	{1, 1331, "Glass Dumpster", 500, 0.0, 0.0},
	{1, 1333, "Waste Dumpster", 500, 0.0, 0.0},
	{1, 1334, "Secured Dumpster", 500, 0.0, 0.0},
	{1, 19831, "BBQ", 700, 0.0, 0.0},
	{1, 1481, "BBQ 2", 1000, 0.0, 0.0},
	{1, 1369, "Old Wheelchair", 500, 0.0, 0.0},
	{1, 1679, "Table & Chairs", 900, 0.0, 0.0},
	{1, 1594, "Table & Chairs 2", 900, 0.0, 0.0},
	{1, 1825, "Table & Chairs 3", 900, 0.0, 0.0},
	{1, 642, "Umbrella", 500, 0.0, 0.0},
	{1, 1438, "Boxes", 500, 0.0, 0.0},
	{1, 1440, "Boxes 2", 500, 0.0, 0.0},
	{1, 3408, "Mail Box", 500, 0.0, 0.0},
	{1, 19867, "Mail Box 2", 500, 0.0, 0.0},
	{1, 19626, "Spade", 600, 0.0, 0.0},
	{1, 19631, "Sledge Hammer", 600, 0.0, 0.0},
	{1, 1255, "Pool seat", 900, 0.0, 0.0},
	{1, 1432, "Table", 500, 0.0, 0.0},
	{1, 1547, "Beach towel", 200, 0.0, 0.0},
	{1, 1640, "Beach towel 2", 200, 0.0, 0.0},
	{1, 1642, "Beach towel 3", 200, 0.0, 0.0},
	{1, 1643, "Beach towel 4", 200, 0.0, 0.0},
	{1, 2818, "Beach towel 5", 200, 0.0, 0.0},
	{1, 2817, "Beach towel 6", 200, 0.0, 0.0},
	{1, 914, "Window vent", 400, 0.0, 0.0},
	{1, 916, "Empty tray", 200, 0.0, 0.0},
	{1, 917, "Empty tray large", 1000, 0.0, 0.0},
	{1, 922, "Boxes", 1000, 0.0, 0.0},
	{1, 923, "Boxes 2", 1000, 0.0, 0.0},
	{1, 924, "Empty trays", 1000, 0.0, 0.0},
	{1, 925, "Oil tanks", 1000, 0.0, 0.0},
	{1, 926, "Empty boxes", 1000, 0.0, 0.0},
	{1, 930, "Tanks", 1000, 0.0, 0.0},
	{1, 931, "Empty cage", 1000, 0.0, 0.0},
	{1, 933, "Wheel", 1000, 0.0, 0.0},
	{1, 935, "Oil Drum", 1000, 0.0, 0.0},
	{1, 1220, "Boxes 3", 1000, 0.0, 0.0},
	{1, 1227, "Dumpster", 1000, 0.0, 0.0},
	{1, 1264, "Trash bag", 1000, 0.0, 0.0},
	{1, 1271, "Wood crate", 1000, 0.0, 0.0},
	{1, 1300, "Outdoor bin", 1000, 0.0, 0.0},
	{1, 1327, "Tire", 1000, 0.0, 0.0},
	{1, 1328, "Trashcan", 1000, 0.0, 0.0},
	{1, 1349, "Trolley", 1000, 0.0, 0.0},
	{1, 1428, "Ladder", 1000, 0.0, 0.0},
	{1, 1437, "Ladder2", 1000, 0.0, 0.0},
	{1, 1440, "Trash bags", 1000, 0.0, 0.0},
	{1, 1451, "Kennel", 1000, 0.0, 0.0},
	{1, 1454, "Hay ball", 1000, 0.0, 0.0},
	{1, 1457, "Shack", 1000, 0.0, 0.0},
	{1, 1458, "Trailer", 1000, 0.0, 0.0},
	{1, 1463, "Wood pile", 1000, 0.0, 0.0},
	{1, 1490, "Tagging", 1000, 0.0, 0.0},
	{1, 1595, "Satellite dish", 1000, 0.0, 0.0},
	{1, 1598, "Beach Ball", 1000, 0.0, 0.0},
	{1, 1946, "Basket Ball", 1000, 0.0, 0.0},
	{1, 1617, "AC 2", 1000, 0.0, 0.0},
	{1, 1639, "Volleyball net", 1000, 0.0, 0.0},
	{1, 1689, "Roof vent", 1000, 0.0, 0.0},
	{1, 1691, "Roof vent2", 1000, 0.0, 0.0},
	{1, 2203, "Pot plants", 1000, 0.0, 0.0},
	{1, 2228, "Shovel", 1000, 0.0, 0.0},
	{1, 2237, "Shovel2", 1000, 0.0, 0.0},
	{1, 1492, "Door 1 (moves)", 900, 0.0, 0.0},//Structural Changes 628
	{1, 1493, "Door 2", 900, 0.0, 0.0},
	{1, 3061, "Door 3", 900, 0.0, 0.0},
	{1, 1505, "Door 4", 900, 0.0, 0.0},
	{1, 1495, "Door 5", 900, 0.0, 0.0},
	{1, 1507, "Door 6", 900, 0.0, 0.0},
	{1, 19860, "Door 7", 900, 0.0, 0.0},
	{1, 1532, "Door 8", 900, 0.0, 0.0},
	{1, 2911, "Door 9", 900, 0.0, 0.0},
	{1, 3029, "Door 10 (breaks)", 900, 0.0, 0.0},
	{1, 1569, "Door 11", 900, 0.0, 0.0},
	{1, 2877, "Door 12", 900, 0.0, 0.0},
	{1, 1566, "Door 13", 900, 0.0, 0.0},
	{1, 19802, "Door 14", 900, 0.0, 0.0},
	{1, 11714, "Door 15", 900, 0.0, 0.0},
	{1, 19858, "Door 16", 900, 0.0, 0.0},
	{1, 1535, "Door 17", 900, 0.0, 0.0},
	{1, 1556, "Door 18", 900, 0.0, 0.0},
	{1, 1555, "Door 19", 900, 0.0, 0.0},
	{1, 1538, "Door 20", 900, 0.0, 0.0},
	{1, 1536, "Door 21", 900, 0.0, 0.0},
	{1, 1506, "Door 22", 900, 0.0, 0.0},
	{1, 1504, "Door 23", 900, 0.0, 0.0},
	{1, 1502, "Door 24 (moves)", 900, 0.0, 0.0},
	{1, 1501, "Door 25", 900, 0.0, 0.0},
	{1, 1499, "Door 26 (moves)", 900, 0.0, 0.0},
	{1, 1498, "Door 27", 900, 0.0, 0.0},
	{1, 1497, "Door 28", 900, 0.0, 0.0},
	{1, 1496, "Door 29", 900, 0.0, 0.0},
	{1, 1494, "Door 30 (moves)", 900, 0.0, 0.0},
	{1, 1491, "Door 31 (moves)", 900, 0.0, 0.0},
	{1, 2949, "Door 32", 900, 0.0, 0.0},
	{1, 19466, "Window 1", 500, 0.0, 0.0},
	{1, 3034, "Window 2", 500, 0.0, 0.0},
	{1, 3032, "Window 3", 500, 0.0, 0.0},
	{1, 14902, "Windows", 600, 0.0, 0.0},
	{1, 14892, "Posh Windows", 1000, 0.0, 0.0},
	{1, 11103, "Old Window", 400, 0.0, 0.0},
	{1, 3278, "Cottage Window", 500, 0.0, 0.0},
	{1, 14740, "Blinds", 900, 0.0, 0.0},
	{1, 18084, "Blind", 600, 0.0, 0.0},
	{1, 2558, "Curtains 1", 500, 0.0, 0.0},
	{1, 2559, "Curtains 2", 500, 0.0, 0.0},
	{1, 2560, "Curtains 3", 500, 0.0, 0.0},
	{1, 2561, "Curtains 4", 500, 0.0, 0.0},
	{1, 14752, "Curtains 5", 500, 0.0, 0.0},
	{1, 19368, "Beige Wall", 900, 0.0, 0.0},
	{1, 19397, "Beige Doorway", 900, 0.0, 0.0},
	{1, 19367, "Blue Wall", 900, 0.0, 0.0},
	{1, 19395, "Blue Doorway", 900, 0.0, 0.0},
	{1, 19369, "Grey Wall", 900, 0.0, 0.0},
	{1, 19396, "Grey Doorway", 900, 0.0, 0.0},
	{1, 19364, "Brick Wall", 900, 0.0, 0.0},
	{1, 19393, "Brick Doorway", 900, 0.0, 0.0},
	{1, 19354, "Wallpaper Wall", 900, 0.0, 0.0},
	{1, 19384, "Wallpaper Doorway", 900, 0.0, 0.0},
	{1, 19358, "Carpet Wall", 900, 0.0, 0.0},
	{1, 19388, "Carpet Doorway", 900, 0.0, 0.0},
	{1, 2755, "China Wall", 900, 0.0, 0.0},
	{1, 14456, "Roof Patterns", 900, 0.0, 0.0},
	{1, 1354, "Fan", 600, 0.0, 0.0},
	{1, 919, "Air Con", 800, 0.0, 0.0},
	{1, 2653, "Vent", 900, 0.0, 0.0},
	{1, 2649, "Vent 2", 900, 0.0, 0.0},
	{1, 3470, "Vent 3", 900, 0.0, 0.0},
	{1, 19814, "Wall Socket", 200, 0.0, 0.0}
};

enum furnInfo {
	f_ID, //id (prob un-needed)
	f_HouseID,
	f_SQLHouseID, //sql house id
	f_ModelID,
	f_ModelName[50],
	f_Spawned,
	f_ObjectID,
	f_Outdoor,
	f_VirtualWorld,
	Float:f_X,
	Float:f_Y,
	Float:f_Z,
	Float:f_RX,
	Float:f_RY,
	Float:f_RZ
}
new FurnitureInfo[MAX_HOUSES][MAX_FURNITURE][furnInfo];

new EditingFurnitureObjectID[MAX_PLAYERS] = -1;
new EditingFurnitureHouseID[MAX_PLAYERS] = -1;
new EditingFurnitureID[MAX_PLAYERS] = -1;

stock FindEmptyFurnitureSlot(houseid) {
	for(new i = 0; i < MAX_FURNITURE; i++) {
		if( !FurnitureInfo[houseid][i][f_ModelID] ) { //find empty slot without a modelid
			return i;
		}
	}
	return -1;
}

stock GetTotalFurnitureOutdoor(houseid) {
	new count = 0;
	for(new i = 0; i < MAX_FURNITURE; i++) {
		if(FurnitureInfo[houseid][i][f_Outdoor]) { //find empty slot without a modelid
			if( count >= MAX_OUTDOOR_FURNITURE ) { //limit max outside
				return count;
			}
			count++;
		}
	}
	return count;
}

stock LoadFurniture(houseid, sqlhouseid) {
	new query[200];
	mysql_format(sqlGameConnection, query, sizeof(query), "SELECT * FROM `furniture` WHERE `HouseID` = '%d' AND `Active`=1", sqlhouseid);
	mysql_tquery(sqlGameConnection, query, "OnLoadFurniture", "i", houseid);
}

forward OnLoadFurniture(houseid);
public OnLoadFurniture(houseid) {
	if(cache_num_rows() == 0) return printf("[Furniture] WARNING: No furniture found for house id %d but hasFurniture is set to true.", houseid);
	
	new count = 0, outdoorc; //count of outdoor furniture
	//for each furniture object found in the database, put the data into array
	for(new i = 0; i < cache_num_rows(); i++)
	{
		FurnitureInfo[houseid][i][f_ID] = cache_get_field_content_int(i, "ID");
		FurnitureInfo[houseid][i][f_HouseID] = houseid;
		FurnitureInfo[houseid][i][f_SQLHouseID] = cache_get_field_content_int(i, "HouseID"); //sql id
		FurnitureInfo[houseid][i][f_ModelID] = cache_get_field_content_int(i, "ModelID");
		cache_get_field_content(i, "ModelName", FurnitureInfo[houseid][i][f_ModelName], sqlGameConnection, 50);
		FurnitureInfo[houseid][i][f_Spawned] = cache_get_field_content_int(i, "Spawned");
		FurnitureInfo[houseid][i][f_Outdoor] = cache_get_field_content_int(i, "Outdoor");
		if( FurnitureInfo[houseid][i][f_Outdoor] ) {
			if( outdoorc == MAX_OUTDOOR_FURNITURE ) {
				continue;
			}
			outdoorc++;
		}
		// FurnitureInfo[houseid][i][f_VirtualWorld] = cache_get_field_content_int(i, "VirtualWorld");
		FurnitureInfo[houseid][i][f_VirtualWorld] = HouseInfo[houseid][hWorld];
		FurnitureInfo[houseid][i][f_X] = cache_get_field_content_float(i, "X");
		FurnitureInfo[houseid][i][f_Y] = cache_get_field_content_float(i, "Y");
		FurnitureInfo[houseid][i][f_Z] = cache_get_field_content_float(i, "Z");
		FurnitureInfo[houseid][i][f_RX] = cache_get_field_content_float(i, "rX");
		FurnitureInfo[houseid][i][f_RY] = cache_get_field_content_float(i, "rY");
		FurnitureInfo[houseid][i][f_RZ] = cache_get_field_content_float(i, "rZ");
		
		if( FurnitureInfo[houseid][i][f_Spawned] ) {
			FurnitureInfo[houseid][i][f_ObjectID] = CreateDynamicObject(FurnitureInfo[houseid][i][f_ModelID], FurnitureInfo[houseid][i][f_X], FurnitureInfo[houseid][i][f_Y], FurnitureInfo[houseid][i][f_Z], FurnitureInfo[houseid][i][f_RX], FurnitureInfo[houseid][i][f_RY], FurnitureInfo[houseid][i][f_RZ], FurnitureInfo[houseid][i][f_VirtualWorld]);
		}
		HouseInfo[houseid][hFurnitureAmount]++;
		count++;
	}
	//printf("[Furniture] Successfully loaded %d furniture objects for houseid %d.", count, houseid);
	return 1;
}

stock CreateHouseFurniture(playerid, houseid, modelid, index) {
	
	//check for empty furniture slot in owners house
	new empty_slot = FindEmptyFurnitureSlot(houseid);
	
	if(empty_slot != -1) {
	
		//is it outdoor?
		new vw = GetPlayerVirtualWorld(playerid);
		if(vw) { //player is inside
			FurnitureInfo[houseid][empty_slot][f_VirtualWorld] = vw;
		} else {
			if(PlayerInfo[playerid][pDonateRank] < 3) {
				return SendClientMessage(playerid, COLOR_GREY, "You must be a Gold VIP to build outside your house.");
			}
			if( GetTotalFurnitureOutdoor( houseid ) >= MAX_OUTDOOR_FURNITURE ) {
				return SendClientMessage( playerid, COLOR_GREY, "You cannot have anymore furniture outside, the limit is 5." );
			}
			FurnitureInfo[houseid][empty_slot][f_Outdoor] = 1;
		}
		
		//spawn the object
		new Float:fPos[4];
		GetXYInFrontOfPlayer(playerid, fPos[0], fPos[1], fPos[2], fPos[3], 4);
		FurnitureInfo[houseid][empty_slot][f_ObjectID] = CreateDynamicObject(modelid, fPos[0], fPos[1], fPos[2], 0.0, 0.0, 0.0, FurnitureInfo[houseid][empty_slot][f_VirtualWorld] );
		EditDynamicObject(playerid, FurnitureInfo[houseid][empty_slot][f_ObjectID]);
		
		//update array
		FurnitureInfo[houseid][empty_slot][f_Spawned] = 1;
		FurnitureInfo[houseid][empty_slot][f_X] = fPos[0];
		FurnitureInfo[houseid][empty_slot][f_Y] = fPos[1];
		FurnitureInfo[houseid][empty_slot][f_Z] = fPos[2];
		
		FurnitureInfo[houseid][empty_slot][f_ModelID] = modelid;
		format(FurnitureInfo[houseid][empty_slot][f_ModelName], 64, "%s", FurnitureObjectList[index][fD_name]);
		FurnitureInfo[houseid][empty_slot][f_HouseID] = houseid;
		FurnitureInfo[houseid][empty_slot][f_SQLHouseID] = HouseInfo[houseid][hSQLID];
		

		
		//set editmode vars
		EditingFurnitureObjectID[playerid] = FurnitureInfo[houseid][empty_slot][f_ObjectID];
		EditingFurnitureHouseID[playerid] = houseid;
		EditingFurnitureID[playerid] = empty_slot;
		
		//purchase it
		GiveMoney(playerid, -FurnitureObjectList[index][fD_price]);
		format(str, sizeof(str), "* You have purchased a %s for $%d.", FurnitureObjectList[index][fD_name], FurnitureObjectList[index][fD_price]);
		SendClientMessage(playerid, COLOR_LIGHTBLUE, str);
		
		//this tells the loadhouses function to load the furniture when there is a gmx
		if(!HouseInfo[houseid][hHasFurniture]) {
			HouseInfo[houseid][hHasFurniture] = 1;
			HouseInfo[houseid][hModified] = 1;
		}
			
		HouseInfo[houseid][hFurnitureAmount]++;
		
		//no more "hash", there could've been collisions, instead there's a simplier more effective method,
		new query[400];
		mysql_format(sqlGameConnection, query, sizeof(query), "INSERT INTO `furniture` (`Active`, `HouseID`, `ModelID`, `ModelName`, `VirtualWorld`, `Outdoor`, `Spawned`, `X`, `Y`, `Z`) VALUES(1, '%d', '%d', '%e', '%d', '%d', '%d', '%f', '%f', '%f')",
		FurnitureInfo[houseid][empty_slot][f_SQLHouseID], FurnitureInfo[houseid][empty_slot][f_ModelID], FurnitureInfo[houseid][empty_slot][f_ModelName], FurnitureInfo[houseid][empty_slot][f_VirtualWorld], FurnitureInfo[houseid][empty_slot][f_Outdoor], FurnitureInfo[houseid][empty_slot][f_Spawned], FurnitureInfo[houseid][empty_slot][f_X], FurnitureInfo[houseid][empty_slot][f_Y], FurnitureInfo[houseid][empty_slot][f_Z]);
		mysql_pquery(sqlGameConnection, query, "onCreateFurniture", "ii", houseid, empty_slot);
		
	}
	return 1;
}

forward onCreateFurniture(houseid, empty_slot);
public onCreateFurniture(houseid, empty_slot) {
	new query[200];
	//ORDER BY ID DESC LIMIT 1: gets the last "unique" ID in list, AKA last created furniture given houseID
	mysql_format(sqlGameConnection, query, sizeof(query), "SELECT `ID` FROM `furniture` WHERE `HouseID` = %d ORDER BY ID DESC LIMIT 1;", HouseInfo[houseid][hSQLID]);
	mysql_pquery(sqlGameConnection, query, "SetPlayerFurnitureID", "ii", houseid, empty_slot);
	return 1;
}

forward SetPlayerFurnitureID(houseid, empty_slot);
public SetPlayerFurnitureID(houseid, empty_slot) {
	FurnitureInfo[houseid][empty_slot][f_ID] = cache_get_field_content_int(0, "ID");
}

stock DeleteHouseFurniture(houseid, furnitureid) {
	//destroy the object
	if( IsValidDynamicObject( FurnitureInfo[houseid][furnitureid][f_ObjectID] ) ) {
		DestroyDynamicObjectEx(FurnitureInfo[houseid][furnitureid][f_ObjectID]);
	}
	
	//sql update
	new query[200];
	mysql_format(sqlGameConnection, query, sizeof(query), "UPDATE `furniture` SET `Active`=0 WHERE `ID`=%d", FurnitureInfo[houseid][furnitureid][f_ID]);
	mysql_pquery(sqlGameConnection, query);
	
	//clear info
	FurnitureInfo[houseid][furnitureid][f_ID] = 0;
	FurnitureInfo[houseid][furnitureid][f_HouseID] = 0;
	FurnitureInfo[houseid][furnitureid][f_SQLHouseID] = 0;
	FurnitureInfo[houseid][furnitureid][f_ModelID] = 0;
	format(FurnitureInfo[houseid][furnitureid][f_ModelName], 64, "%s", "Empty");
	FurnitureInfo[houseid][furnitureid][f_Spawned] = 0;
	FurnitureInfo[houseid][furnitureid][f_ObjectID] = 0;
	FurnitureInfo[houseid][furnitureid][f_Outdoor] = 0;
	FurnitureInfo[houseid][furnitureid][f_VirtualWorld] = 0;
	FurnitureInfo[houseid][furnitureid][f_X] = 0;
	FurnitureInfo[houseid][furnitureid][f_Y] = 0;
	FurnitureInfo[houseid][furnitureid][f_Z] = 0;
	FurnitureInfo[houseid][furnitureid][f_RX] = 0;
	FurnitureInfo[houseid][furnitureid][f_RY] = 0;
	FurnitureInfo[houseid][furnitureid][f_RZ] = 0;
	
	HouseInfo[houseid][hFurnitureAmount]--;
	
	if(HouseInfo[houseid][hFurnitureAmount] < 1) {
		HouseInfo[houseid][hHasFurniture] = 0;
		HouseInfo[houseid][hModified] = 1;
	}
	return 1;
}

stock ClearHouseFurniture(houseid) {
	for(new i = 0; i < MAX_FURNITURE; i++) {
		if(FurnitureInfo[houseid][i][f_ObjectID] && FurnitureInfo[houseid][i][f_Spawned]) {
			if(IsValidDynamicObject(FurnitureInfo[houseid][i][f_ObjectID])) {
				DestroyDynamicObjectEx(FurnitureInfo[houseid][i][f_ObjectID]);
			}
		}
		
		FurnitureInfo[houseid][i][f_ID] = 0;
		FurnitureInfo[houseid][i][f_HouseID] = 0;
		FurnitureInfo[houseid][i][f_SQLHouseID] = 0;
		FurnitureInfo[houseid][i][f_ModelID] = 0;
		format(FurnitureInfo[houseid][i][f_ModelName], 64, "%s", "Empty");
		FurnitureInfo[houseid][i][f_Spawned] = 0;
		FurnitureInfo[houseid][i][f_ObjectID] = 0;
		FurnitureInfo[houseid][i][f_Outdoor] = 0;
		FurnitureInfo[houseid][i][f_VirtualWorld] = 0;
		FurnitureInfo[houseid][i][f_X] = 0;
		FurnitureInfo[houseid][i][f_Y] = 0;
		FurnitureInfo[houseid][i][f_Z] = 0;
		FurnitureInfo[houseid][i][f_RX] = 0;
		FurnitureInfo[houseid][i][f_RY] = 0;
		FurnitureInfo[houseid][i][f_RZ] = 0;
	}
	
	new query[200];
	mysql_format(sqlGameConnection, query, sizeof(query), "UPDATE `furniture` SET `Active` = 0 WHERE `houseid` = %d", HouseInfo[houseid][hSQLID]);
	mysql_tquery(sqlGameConnection, query);
	return 1;
}

//commands
CMD:furniture( playerid, params[] ) {
	//if(PlayerInfo[playerid][pDev] < 1 && PlayerInfo[playerid][pAdmin] < 1) return SendClientMessage(playerid, COLOR_GREY, "You are not authorized to use this.");
	
	new houseid = PlayerInfo[playerid][pHouseID];
	if(houseid == 0) return SendClientMessage( playerid, COLOR_GRAD1, "You do not own a house.");
	if(HouseInfo[houseid][hOwnerID] != PlayerInfo[playerid][pID]) return SendClientMessage(playerid, COLOR_GREY, "You don't own this house.");
	
	if(IsPlayerInRangeOfPoint(playerid, 100.0, HouseInfo[houseid][hInsideX], HouseInfo[houseid][hInsideY], HouseInfo[houseid][hInsideZ]) && GetPlayerVirtualWorld(playerid) == HouseInfo[houseid][hSQLID]) { //inside
		ShowPlayerDialog(playerid, DIALOG_FURNITURE_MAIN, DIALOG_STYLE_LIST, "Furniture", "Buy furniture\nEdit furniture", "Select", "Cancel");
		return 1;
	} else if(IsPlayerInRangeOfPoint(playerid, 30.0, HouseInfo[houseid][hOutsideX], HouseInfo[houseid][hOutsideY], HouseInfo[houseid][hOutsideZ])) { //outside
		if(PlayerInfo[playerid][pDonateRank] < 3) return SendClientMessage(playerid, COLOR_GREY, "You must be a Gold VIP to build outside your house.");
		
		ShowPlayerDialog(playerid, DIALOG_FURNITURE_MAIN, DIALOG_STYLE_LIST, "Furniture", "Buy furniture\nEdit furniture", "Select", "Cancel");
		return 1;
	} else {
		SendClientMessage(playerid, COLOR_GRAD1, "You are not inside your house or within 30m of the house.");
	}
	
	return 1;
}

CMD:furnitureinfo(playerid, params[])
{
	if(PlayerInfo[playerid][pAdmin] >= 1 || PlayerInfo[playerid][pBizMod] == 1)
	{
		for(new i = 0; i < MAX_HOUSES; i++)
		{
			for(new f = 0; f < MAX_FURNITURE; f++) {
				if(FurnitureInfo[i][f][f_ObjectID]) {
					if(FurnitureInfo[i][f][f_Spawned]) {
						if(IsPlayerInRangeOfPoint(playerid, 2.5, FurnitureInfo[i][f][f_X], FurnitureInfo[i][f][f_Y], FurnitureInfo[i][f][f_Z]))
						{
							format(str, sizeof(str), "Furniture ID: %d | House ID: %d | SQL ID %d | | Model ID %d | Model Name: %s.", f, FurnitureInfo[i][f][f_HouseID], FurnitureInfo[i][f][f_ID], FurnitureInfo[i][f][f_ModelID], FurnitureInfo[i][f][f_ModelName]);
							SendClientMessage(playerid, COLOR_GREY, str);
							format(str, sizeof(str), "Object ID: %d | Virtual World: %d | ObjectVW: %d.", FurnitureInfo[i][f][f_ObjectID], FurnitureInfo[i][f][f_VirtualWorld], Streamer_GetIntData(STREAMER_TYPE_OBJECT, FurnitureInfo[i][f][f_ObjectID], E_STREAMER_WORLD_ID));
							SendClientMessage(playerid, COLOR_GREY, str);
						}
					}
				}
			}	
		}
	}
	return 1;
}

CMD:deletefurniture(playerid, params[])
{
	if(PlayerInfo[playerid][pAdmin] >= 4 || PlayerInfo[playerid][pBizMod] == 1 || PlayerInfo[playerid][pDev] >= 3 )
	{
		new houseid,furnitureid;
		if(sscanf(params, "dd", houseid, furnitureid)) return SendClientMessage(playerid, COLOR_GREY, "{00BFFF}Usage:{FFFFFF} /deletefurniture [houseid] [furnitureid]");
		if(!FurnitureInfo[houseid][furnitureid][f_ObjectID]) return SendClientMessage(playerid, COLOR_GREY, "There is no furniture object in that slot.");
		
		format(str, sizeof(str), "* You have deleted the %s.", FurnitureInfo[houseid][furnitureid][f_ModelName]);
		SendClientMessage(playerid, COLOR_LIGHTBLUE, str);
		
		DeleteHouseFurniture(houseid, furnitureid);
	}
	else
	{
		AdmErrorMsg;
	}
	return 1;
}

CMD:resethousefurniture(playerid, params[])
{
	if(PlayerInfo[playerid][pAdmin] >= 4 || PlayerInfo[playerid][pBizMod] == 1)
	{
		new houseid;
		if(sscanf(params, "d", houseid)) return SendClientMessage(playerid, COLOR_GREY, "{00BFFF}Usage:{FFFFFF} /resethousefurniture [houseid]");
		
		ClearHouseFurniture(houseid);
		
		HouseInfo[houseid][hFurnitureAmount] = 0;
		HouseInfo[houseid][hHasFurniture] = 0;
		HouseInfo[houseid][hModified] = 1;
		format(str, sizeof(str), "You have reset houseid %d's furniture.", houseid);
		SendClientMessage(playerid, COLOR_GRAD1, str);
	}
	else
	{
		AdmErrorMsg;
	}
	return 1;
}

CMD:fdb(playerid, params[])
{
	new houseid;
	if(sscanf(params, "d", houseid)) return SendClientMessage(playerid, COLOR_GREY, "{00BFFF}Usage:{FFFFFF} /fdb [houseid]");
	
	for(new f = 0; f < 5; f++) {
		
		format(str, sizeof(str), "Furniture ID: %d | House ID: %d | SQL ID %d | | Model ID %d | Model Name: %s.", f, FurnitureInfo[houseid][f][f_HouseID], FurnitureInfo[houseid][f][f_ID], FurnitureInfo[houseid][f][f_ModelID], FurnitureInfo[houseid][f][f_ModelName]);
		SendClientMessage(playerid, COLOR_GREY, str);
		format(str, sizeof(str), "Spawned: %d | Object ID: %d | Outdoor:%d | Virtual World: %d.", FurnitureInfo[houseid][f][f_Spawned], FurnitureInfo[houseid][f][f_ObjectID], FurnitureInfo[houseid][f][f_Outdoor], FurnitureInfo[houseid][f][f_VirtualWorld]);
		SendClientMessage(playerid, COLOR_LIGHTBLUE, str);
		format(str, sizeof(str), "f_X: %f | f_Y: %f | f_Z: %f", FurnitureInfo[houseid][f][f_X], FurnitureInfo[houseid][f][f_Y], FurnitureInfo[houseid][f][f_Z]);
		SendClientMessage(playerid, COLOR_WHITE, str);
	}
	return 1;
}

CMD:deleteallfurniture(playerid, params[])
{
	new houseid = PlayerInfo[playerid][pHouseID];
	if(houseid == 0) return SendClientMessage( playerid, COLOR_GRAD1, "You do not own a house.");
	if(HouseInfo[houseid][hOwnerID] != PlayerInfo[playerid][pID]) return SendClientMessage(playerid, COLOR_GREY, "You don't own this house.");
	if(!IsPlayerInRangeOfPoint(playerid, 100.0, HouseInfo[houseid][hInsideX], HouseInfo[houseid][hInsideY], HouseInfo[houseid][hInsideZ]) && GetPlayerVirtualWorld(playerid) != HouseInfo[houseid][hSQLID]) return SendClientMessage(playerid, COLOR_GRAD1, "You are not inside your house.");  //inside

	ClearHouseFurniture(houseid);	
	SendClientMessage(playerid, COLOR_GREY, "You have deleted all of your house's furniture.");
	return 1;
}

CMD:togglefurniture(playerid, params[])
{
	new houseid = PlayerInfo[playerid][pHouseID];
	if(houseid == 0) return SendClientMessage( playerid, COLOR_GRAD1, "You do not own a house.");
	if(HouseInfo[houseid][hOwnerID] != PlayerInfo[playerid][pID]) return SendClientMessage(playerid, COLOR_GREY, "You don't own this house.");
	new action[4];
	if(sscanf(params, "s[4]", action)) return SendClientMessage(playerid, -1, "{00BFFF}Usage:{FFFFFF} /togglefurniture [on/off]");
	if(!strcmp(action, "off", true)) // hide
	{
		for(new i = 0; i < MAX_FURNITURE; i++) // loop through all furniture
		{
			if(FurnitureInfo[houseid][i][f_Spawned]) // if it's a spawned furniture in the player's house, destroy it (hide)
			{ 
				FurnitureInfo[houseid][i][f_Spawned] = 0;
				if(FurnitureInfo[houseid][i][f_ObjectID]) { DestroyDynamicObjectEx(FurnitureInfo[houseid][i][f_ObjectID]); }
				FurnitureInfo[houseid][i][f_ObjectID] = 0;
			}
		} 

		//sql update
		new query[200];
		mysql_format(sqlGameConnection, query, sizeof(query), "UPDATE `furniture` SET `Spawned`=0 WHERE `houseid` = %d", HouseInfo[houseid][hSQLID]);
		mysql_pquery(sqlGameConnection, query);
		SendClientMessage(playerid, COLOR_LIGHTBLUE, "* You have hidden all of your furniture.");
	}
	else if(!strcmp(action, "on", true)) //unhide
	{
		for(new i = 0; i < MAX_FURNITURE; i++) // loop through all furniture
		{
			if(!FurnitureInfo[houseid][i][f_Spawned]) // if it's a not spawned furniture in the player's house, create it it (unhide)
			{ 
				FurnitureInfo[houseid][i][f_ObjectID] = CreateDynamicObject(FurnitureInfo[houseid][i][f_ModelID], FurnitureInfo[houseid][i][f_X], FurnitureInfo[houseid][i][f_Y], FurnitureInfo[houseid][i][f_Z], FurnitureInfo[houseid][i][f_RX], FurnitureInfo[houseid][i][f_RY], FurnitureInfo[houseid][i][f_RZ]);
				FurnitureInfo[houseid][i][f_Spawned] = 1;
				Streamer_Update(playerid);
			}
		} 

		//sql update
		new query[200];
		mysql_format(sqlGameConnection, query, sizeof(query), "UPDATE `furniture` SET `Spawned`=1 WHERE `houseid` = %d", HouseInfo[houseid][hSQLID]);
		mysql_pquery(sqlGameConnection, query);
		SendClientMessage(playerid, COLOR_LIGHTBLUE, "* You have unhidden all of your furniture.");	
	}		
	return 1;
}