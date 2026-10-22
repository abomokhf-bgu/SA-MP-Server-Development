/*

	file:			customs_skins/array.inc

	description:	The custom skin registration system. (array)

	author:			Jay Cortez

	date created:	28th March 2018

*/

#if defined INC_CUSTOM_SKIN_ARR
	#endinput
#endif

#define INC_CUSTOM_SKIN_ARR
#define MAX_CUSTOM_SKINS	600

enum customSkinEnum {
	bool:cs_Used,
	cs_SkinID,
	cs_SkinType,
	cs_Meta1,
	cs_Meta2
};
new CustomSkin[MAX_CUSTOM_SKINS][customSkinEnum];