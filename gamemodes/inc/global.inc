#include <YSI\y_hooks>

hook OnScriptInit()
{
    SetTimer("gunmuteplayertimer", 1000, 1);
    return 1;
}

#define		COLOR_ERROR		0xFF5757FF
#define     COLOR_ADMINS    0xFF5757FF

CMD:gmute(playerid, params[]){
    if(PlayerInfo[playerid][pAdmin] < 1337)
		return AdmErrorMsg;
    new 
        targetid, 
        str[256],
        hours,
        query[128]
    ;
    if(sscanf(params, "d", targetid)) return SendClientMessage(playerid, COLOR_GREY, "{00BFFF}Usage:{FFFFFF} /gmute [playerid] [hours - leaving it empty gives permanent mute.]");
    if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid, COLOR_GREY, "{FF0000}Error:{FFFFFF} Invalid player id.");
    if(PlayerInfo[targetid][pGCMute] == 1) return SendClientMessage(playerid, COLOR_GREY, "{FF0000}Error: {FFFFFF}That player is already muted.");
    if(hours > 25) return SendClientMessage(playerid, COLOR_GREY, "{FF0000}Error: {FFFFFF}Please select between 1-25 hours - or leave it empty for permanet mute");
    if(sscanf(params, "dd", targetid, hours)){
        PlayerInfo[targetid][pGCMutePerm] = 1;
        SendClientMessage(targetid, COLOR_WHITE, "{FF0000}Warning{FFFFFF}: You were permanently muted from global chat.");
        format(str, sizeof(str), "{FF0000}AdmWarning{FFFFFF}: %s was permanently muted from global chat by %s.", PlayerName(targetid), PlayerName(playerid));
        ABroadCast(COLOR_WHITE, str, 1);
        mysql_format(sqlGameConnection, query, sizeof(query), "UPDATE `players` SET `GCMutePerm`= 1 WHERE `Name`='%e'", PlayerName(targetid));
	    mysql_pquery(sqlGameConnection, query);
    } else {
        format(str, sizeof(str), "{FF0000}WARNING{FFFFFF}: You were muted from global chat for %d hours.", hours);
        SendClientMessage(targetid, COLOR_WHITE, str);
        format(str, sizeof(str), "{FF0000}AdmWarning{FFFFFF}: %s was muted from global chat by %s for %d hours.", PlayerName(targetid), PlayerName(playerid), hours);
        ABroadCast(COLOR_WHITE, str, 1);
        new calc = hours*3600;
        PlayerInfo[targetid][pGCMute] = 1;
        PlayerInfo[targetid][pGCMuteTimer] = calc;
        mysql_format(sqlGameConnection, query, sizeof(query), "UPDATE `players` SET `GCMute`= 1, `GCMuteTimer` = %d WHERE `Name`='%e'", calc, PlayerName(targetid));
	    mysql_pquery(sqlGameConnection, query);
    }
    return 1;
}
CMD:gunmute(playerid, params[]){
    new query[128];
    if(PlayerInfo[playerid][pAdmin] < 1337)
		return AdmErrorMsg;
    new targetid, str[256];
    if(sscanf(params, "d", targetid)) return SendClientMessage(playerid, COLOR_GREY, "{00BFFF}Usage:{FFFFFF} /gunmute [playerid]");
    if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid, COLOR_GREY, "{FF0000}Error:{FFFFFF} Invalid player id.");
    PlayerInfo[targetid][pGCMute] = 0;
    PlayerInfo[targetid][pGCMuteTimer] = 0;
    PlayerInfo[targetid][pGCMutePerm] = 0;
    SendClientMessage(targetid, COLOR_GREY, "{FF0000}Notification{FFFFFF}: You were unmuted from global chat.");
    format(str, sizeof(str), "{FF0000}AdmWarning{FFFFFF}: %s was unmuted from global chat by %s.", PlayerName(targetid), PlayerName(playerid));
    ABroadCast(COLOR_WHITE, str, 1);
    mysql_format(sqlGameConnection, query, sizeof(query), "UPDATE `players` SET `GCMute`= 0, `GCMuteTimer` = 0, `GCMutePerm` = 0 WHERE `Name`='%e'", PlayerName(targetid));
	mysql_pquery(sqlGameConnection, query);
    return 1;
}
CMD:requestglobalunmute(playerid, params[])
{
	if(PlayerInfo[playerid][pGCMute] != 0)
	{
		if(PlayerInfo[playerid][pGCMutePerm] == 1) return SendClientMessage(playerid, COLOR_GREY, "You may not request an unmute as you are permanently banned from the global channel (post an unmute request on Coming soon)");
		new str[128];
		if(PlayerInfo[playerid][pGCReqTimer] > 0)
		{
			if(PlayerInfo[playerid][pGCReqUnmute] > 3600) format(str, sizeof(str), "You have %d hours left before you can /requestglobalunmute", PlayerInfo[playerid][pGCReqUnmute]/3600);
			else format(str, sizeof(str), "You have %d minutes left before you can /requestglobalunmute", PlayerInfo[playerid][pGCReqUnmute]/60);

			return SendClientMessage(playerid, COLOR_GREY, str);
		}
		if(PlayerInfo[playerid][pGCRequestUnmute] == true) return SendClientMessage(playerid, COLOR_WHITE, "You're already requested an global unmute.");
		new price;
		if(PlayerInfo[playerid][pLevel] <= 3) price = PlayerInfo[playerid][pLevel] * 15000;
		else price = PlayerInfo[playerid][pLevel] * 30000;
		format(str, sizeof(str), "You don't have enough money ($%d) to do this.", price);
		if(PlayerInfo[playerid][pCash] >= price)
		{
			format(str, sizeof(str), "{FF0000}AdmWarning{FFFFFF}: %s (ID %d) has requested to be unmuted from the global chat (/acceptunmute /OR/ /denyunmute)", PlayerICName(playerid), playerid);
			ABroadCast(COLOR_WHITE, str, 1);
			format(str, sizeof(str), "You have requested to be unmuted from the global chat for $%d.", price);
			SendClientMessage(playerid, COLOR_LIGHTBLUE, str);
			PlayerInfo[playerid][pGCRequestUnmute] = true;
			PlayerInfo[playerid][pGCUnmutePrice] = price;
		}
		else return SendClientMessage(playerid, COLOR_GRAD1, str);
	}
	else return SendClientMessage(playerid, COLOR_GRAD1, "You're not muted from the global chat channel.");
	return 1;
}

CMD:gc(playerid, params[]){
    if(PlayerInfo[playerid][pLevel] < 2) return SendClientMessage(playerid, COLOR_GREY, "{FF0000}Error:{FFFFFF} You need to be atleast level 2 to use that command.");
	new message[1024], str[256];
    if(sscanf(params, "s[1024]", message)) return SendClientMessage(playerid, COLOR_GREY, "{00BFFF}Usage:{FFFFFF} /gc [text]");
    if(PlayerInfo[playerid][pGCMutePerm] == 1 || PlayerInfo[playerid][pGCMute]) return SendClientMessage(playerid, COLOR_ERROR, "{FF0000}Error:{FFFFFF} You are banned from speaking in that channel");
    if(AGCTog != 0){
        if(PlayerInfo[playerid][pGCTog] != 0){
            if(PlayerInfo[playerid][pGCTag] != 0){
                if(strlen(message) > MAX_SPLIT_LENGTH){
                    format(str, sizeof(str), "[Global Chat] %s %s [%d]: %.*s", PlayerInfo[playerid][pGCTagName], PlayerOOCName(playerid), playerid, MAX_SPLIT_LENGTH, message);
                    SendGlobalChat(str);
                    format(str, sizeof(str), "[Global Chat] %s %s [%d]: ...%s", PlayerInfo[playerid][pGCTagName], PlayerOOCName(playerid), playerid, message[MAX_SPLIT_LENGTH]);
                    SendGlobalChat(str);
                }
                else{
                    format(str, sizeof(str), "[Global Chat] %s %s [%d]: %s", PlayerInfo[playerid][pGCTagName], PlayerOOCName(playerid), playerid, message);
                    SendGlobalChat(str);
                }
            }
            else{
                if(strlen(message) > MAX_SPLIT_LENGTH){
                    format(str, sizeof(str), "[Global Chat] %s [%d]: %.*s", PlayerOOCName(playerid), playerid, MAX_SPLIT_LENGTH, message);
                    SendGlobalChat(str);
                    format(str, sizeof(str), "[Global Chat] %s [%d]: ...%s", PlayerOOCName(playerid), playerid, message[MAX_SPLIT_LENGTH]);
                    SendGlobalChat(str);
                }
                else{
                    format(str, sizeof(str), "[Global Chat] %s [%d]: %s", PlayerOOCName(playerid), playerid, message);
                    SendGlobalChat(str);
                }
            }
        } else {
            SendClientMessage(playerid, COLOR_GREY, "{FF0000}Error:{FFFFFF} Global chat channel is currently turned off, /togglobal to enable it.");
        }
    } else {
        SendClientMessage(playerid, COLOR_GREY, "{FF0000}Error:{FFFFFF} Global chat channel has been disabled by an admin.");
    }
    return 1;
}
CMD:togglobal(playerid, params[]){
    if(PlayerInfo[playerid][pLevel] < 2) return SendClientMessage(playerid, COLOR_GREY, "{FF0000}Error:{FFFFFF} You need to be atleast level 2 to use that command.");
    if(PlayerInfo[playerid][pLevel] < 2) return 0;
    if(PlayerInfo[playerid][pGCTog] != 0){
        PlayerInfo[playerid][pGCTog] = 0;
        SendClientMessage(playerid, COLOR_GREY, "Global chat channel disabled.");
    } else {
        PlayerInfo[playerid][pGCTog] = 1;
        SendClientMessage(playerid, COLOR_GREY, "Global Chat channel enabled.");
    }
    return 1;
}
CMD:setgtag(playerid, params[]){
    if(PlayerInfo[playerid][pAdmin] < 1337)
		return AdmErrorMsg;
    new targetid, tag[30], str[512], query[128];
    if(sscanf(params, "d", targetid)) return SendClientMessage(playerid, COLOR_GREY, "{00BFFF}Usage:{FFFFFF} /setgtag [playerid] [tag]");
    if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid, COLOR_GREY, "{FF0000}Error:{FFFFFF} Invalid player id.");
    if(sscanf(params, "ds[30]", targetid, tag))
    {
        if(PlayerInfo[targetid][pGCTag] == 1){
            SendClientMessage(targetid, COLOR_GREY, "{FF0000}Warning{FFFFFF}: Your global chat tag has been removed by an Admin.");
            PlayerInfo[targetid][pGCTag] = 0;
            PlayerInfo[targetid][pGCTagName] = 0;
            mysql_format(sqlGameConnection, query, sizeof(query), "UPDATE `players` SET `GCTagName`='None', `GCTag` = 0 WHERE `Name`='%e'", PlayerName(targetid));
            mysql_pquery(sqlGameConnection, query);
            format(str, sizeof(str), "{FF0000}AdmWarning{FFFFFF}: %s's global chat tag has been removed by Admin %s", PlayerName(targetid), PlayerName(playerid));
            ABroadCast(COLOR_WHITE, str, 1);
        } else if(PlayerInfo[targetid][pGCTag] == 0) {
            SendClientMessage(playerid, COLOR_GREY, "{FF0000}Error:{FFFFFF} That player doesn't have any global chat tag.");
        }
    } else {
        format(str, sizeof(str), "{FF0000}Notification{FFFFFF}: Your global chat tag has been set to {FF2200}\"%s\" {FFFFFF}by an Admin.", tag);
        SendClientMessage(targetid, COLOR_GREY, str);
        PlayerInfo[targetid][pGCTag] = 1;
        PlayerInfo[targetid][pGCTagName] = tag;
        mysql_format(sqlGameConnection, query, sizeof(query), "UPDATE `players` SET `GCTagName`='%e', `GCTag` = 1 WHERE `Name`='%e'", tag, PlayerName(targetid));
	    mysql_pquery(sqlGameConnection, query);
        format(str, sizeof(str), "{FF0000}AdmWarning{FFFFFF}: %s's global chat tag has been set to {FF2200}\"%s\"{FFFFFF} by Admin %s.", PlayerName(targetid), tag, PlayerName(playerid));
        ABroadCast(COLOR_WHITE, str, 1);
    }
    return 1;
}
CMD:noglobal(playerid, params[]){
    if(PlayerInfo[playerid][pAdmin] < 1337)
		return AdmErrorMsg;
	new query[128];
    if(AGCTog != 0){
        AGCTog = 0;
        SendClientMessageToAll(COLOR_GREY, "Global chat channel has been disabled by an Admin.");
        mysql_format(sqlGameConnection, query, sizeof(query), "UPDATE `stuff` SET `AGCTog` = %d", AGCTog);
	    mysql_pquery(sqlGameConnection, query);
    } else {
        AGCTog = 1;
        SendClientMessageToAll(COLOR_GREY, "Global chat channel has been enabled by an Admin.");
        mysql_format(sqlGameConnection, query, sizeof(query), "UPDATE `stuff` SET `AGCTog` = %d", AGCTog);
	    mysql_pquery(sqlGameConnection, query);
    }
    return 1;
}
SendGlobalChat(message[]){
    for (new i = 0; i < MAX_PLAYERS; i++) {
        if (IsPlayerConnected(i) && PlayerInfo[i][pGCTog] != 0) SendClientMessage(i, 0xFF9B00FF, message);
    }
}
forward gunmuteplayertimer(playerid);
public gunmuteplayertimer(playerid){
    foreach(new i: Player)
    {
        if(PlayerInfo[i][pGCMuteTimer] != 0)
        {
            PlayerInfo[i][pGCMuteTimer] --;
            if(PlayerInfo[i][pGCMuteTimer] == 0)
            {
                TimeGcUnmute(i);
            }
        }
    }
    return 1;
}
forward TimeGcUnmute(playerid);
public TimeGcUnmute(playerid){
    new str[256];
    PlayerInfo[playerid][pGCMuteTimer] = 0;
    PlayerInfo[playerid][pGCMute] = 0;
    format(str, sizeof(str), "[System]: You have been automatically unmuted after serving your duration.");
    SendClientMessage(playerid, COLOR_ADMINS, str);
    SQLSave(playerid);
    return 1;
}

