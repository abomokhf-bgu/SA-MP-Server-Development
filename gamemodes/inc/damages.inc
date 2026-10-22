#define		DIALOG_DAMAGE		1927
#define		MAX_DAMAGES			1000

#define		SCM					SendClientMessage
#define		FORMAT:%0(%1)		format(%0, sizeof(%0), %1)

enum dmgInfo
{
	dmgDamage,
	dmgWeapon,
	dmgBodypart,
	dmgKevlarhit,
	dmgSeconds,
}
new DamageInfo[MAX_PLAYERS][MAX_DAMAGES][dmgInfo];
stock ResetPlayerDamages(playerid)
{
	for(new i = 0; i < MAX_DAMAGES; i++)
	{
		if(DamageInfo[playerid][i][dmgDamage] != 0)
		{
			DamageInfo[playerid][i][dmgDamage] = 0;
			DamageInfo[playerid][i][dmgWeapon] = 0;
			DamageInfo[playerid][i][dmgBodypart] = 0;
			DamageInfo[playerid][i][dmgKevlarhit] = 0;
			DamageInfo[playerid][i][dmgSeconds] = 0;
		}
	}
	return 1;
}
Hook:d_OnPlayerConnect(playerid)
{
	ResetPlayerDamages(playerid);
	return 1;
}

stock ShowPlayerDamages(playerid, toid)
{
	new 
	str[4096], str1[4096], count = 0, name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, name, sizeof(name));
	for(new i = 0; i < MAX_DAMAGES; i++)
	{
		if(DamageInfo[playerid][i][dmgDamage] != 0) count++;
	}
	if(count == 0) return ShowPlayerDialog(toid, DIALOG_DAMAGE, DIALOG_STYLE_LIST, name, "There is no damage to display...", "Close", "");
	else if(count > 0)
	{
		for(new i = 0; i < MAX_DAMAGES; i++)
		{
			if(DamageInfo[playerid][i][dmgDamage] != 0)
			{
				FORMAT:str1("%d dmg from %s to %s (Kevlarhit: %d) %d s ago\n", DamageInfo[playerid][i][dmgDamage], GetWeaponNameEx(DamageInfo[playerid][i][dmgWeapon]), GetBodypartName(DamageInfo[playerid][i][dmgBodypart]), DamageInfo[playerid][i][dmgKevlarhit], gettime() - DamageInfo[playerid][i][dmgSeconds]);
				strcat(str, str1);
			}
		}
		ShowPlayerDialog(toid, DIALOG_DAMAGE, DIALOG_STYLE_LIST, name, str, "Close", "");
	}
	return 1;
}

CMD:damages(playerid, params[])
{
	new targetid, Float: pPos[3];
	if(sscanf(params, "u", playerid)) return SCM(playerid, 0xFF6347FF, "{00BFFF}Usage:{FFFFFF}/damages [playerid/PartOfName]");
	if(!IsPlayerConnected(playerid)) return SCM(playerid, 0xFF6347FF, "Playerid is not an active player.");
	
	GetPlayerPos(playerid, pPos[0], pPos[1], pPos[2]);
	if(IsPlayerInRangeOfPoint(playerid, 7.0, pPos[0], pPos[1], pPos[2]))
	{
		ShowPlayerDamages(playerid, targetid);
	}
	else return SCM(playerid, 0xB8BAC6FF, "You're too far away.");
	return 1;
}

Hook:d_OnPlayerTakeDamage(playerid, issuerid, Float: amount, weaponid, bodypart)
{
	if(IsPlayerConnected(playerid))
	{
		new Float: pHP, Float: pArm;
		GetPlayerHealth(playerid, pHP);
		GetPlayerArmour(playerid, pArm);
		for(new i = 0; i < MAX_DAMAGES; i++)
		{
			if(!DamageInfo[playerid][i][dmgDamage])
			{
				playerid = i;
				break;
			}
		}
		for(new i = 0; i < MAX_DAMAGES; i++)
		{
			DamageInfo[playerid][i][dmgDamage] = floatround(amount, floatround_round);
			DamageInfo[playerid][i][dmgWeapon] = weaponid;
			DamageInfo[playerid][i][dmgBodypart] = bodypart;
			if(pArm > 0) DamageInfo[playerid][i][dmgKevlarhit] = 1;
			else if(pArm < 1) DamageInfo[playerid][i][dmgKevlarhit] = 0;
			DamageInfo[playerid][i][dmgSeconds] = gettime();
		}

	}
	return 1;
}

stock GetWeaponNameEx(weaponid)
{
	new weaponname[60];
	GetWeaponName(weaponid, weaponname, sizeof(weaponname));
	return weaponname;
}

stock GetBodypartName(bodypart)
{
	new bodyname[60];
	switch(bodypart)
	{
		case BODY_PART_TORSO: FORMAT:bodyname("TORSO");
		case BODY_PART_GROIN: FORMAT:bodyname("GROIN");
		case BODY_PART_RIGHT_ARM: FORMAT:bodyname("RIGHT ARM");
		case BODY_PART_LEFT_ARM: FORMAT:bodyname("LEFT ARM");
		case BODY_PART_RIGHT_LEG: FORMAT:bodyname("RIGHT ARM");
		case BODY_PART_LEFT_LEG: FORMAT:bodyname("LEFT LEG");
		case BODY_PART_HEAD: FORMAT:bodyname("HEAD");
	}
	return bodyname;
}