#include <YSI\y_hooks>

hook OnScriptInit()
{
    SetTimer("gunmuteplayertimer", 1000, 1);
    return 1;
}

#define		COLOR_ERROR		0xFF5757FF
#define     COLOR_WHITE1     0xFFFFFF00
#define     COLOR_ORANGE1    0xFFAF00FF
#define     COLOR_ADMINS    0xFF5757FF
//#define     COLOR_ORANGE2   0xFF9B00FF

new
    agctog,
    gctog[MAX_PLAYERS],
    gctag[MAX_PLAYERS],
    gctagname[MAX_PLAYERS][30],
    gcmute[MAX_PLAYERS],
    gcmuteperm[MAX_PLAYERS],
    gcmutetimer[MAX_PLAYERS]
;
CMD:gmute(playerid, params[]){
    if(!IsPlayerAdmin(playerid)) return 0;
    new id, string[256], hours;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, COLOR_WHITE1, "Usage: /gmute [playerid] [hours - leaving it empty would give player a permanent mute.]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, COLOR_ADMINS, "Error: Invalid player id.");
    if(gcmute[id] == 1) return SendClientMessage(playerid, COLOR_ADMINS, "Error: Player is already muted.");
    if(hours > 25) return SendClientMessage(playerid, COLOR_ADMINS, "Error: Please select between 1-25 hours, leaving it empty would give player a permanent mute.");
    if(sscanf(params, "ds", id, hours)){
        gcmuteperm[id] = 1;
        SendClientMessage(id, COLOR_ADMINS, "[AdmCmd]: An admin has muted you PERMANENTLY from global chat.");
        format(string, sizeof(string), "[AdmCmd]: You have muted %s from global chat permanently.", pname(id));
        SendClientMessage(playerid, COLOR_ADMINS, string);
    } else {
        new calc = hours*3600;
        gcmute[id] = 1;
        gcmutetimer[id] = calc;
        format(string, sizeof(string), "[AdmCmd]: An admin has muted you for %d hours from global chat.", hours);
        SendClientMessage(id, COLOR_ADMINS, string);
        format(string, sizeof(string), "[AdmCmd]: You have muted %s for %d hours from global chat.", pname(id), hours);
        SendClientMessage(playerid, COLOR_ADMINS, string);
    }
    return 1;
}
CMD:gunmute(playerid, params[]){
    if(!IsPlayerAdmin(playerid)) return 0;
    new id, string[256];
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, COLOR_WHITE1, "Usage: /gunmute [playerid]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, COLOR_ERROR, "Error: Invalid player id.");
    gcmute[id] = 0;
    gcmuteperm[id] = 0;
    SendClientMessage(id, COLOR_ADMINS, "[AdmCmd]: An admin has unmuted you from global chat.");
    format(string, sizeof(string), "[AdmCmd]: You have unmuted %s from global chat.", pname(id));
    return 1;
}
CMD:gc(playerid, params[]){
    new message[256], string[512];
    if(sscanf(params, "s", message)) return SendClientMessage(playerid, COLOR_WHITE1, "Usage: /gc [text]");
    if(gcmuteperm[playerid] == 1 || gcmute[playerid]) return SendClientMessage(playerid, COLOR_ERROR, "Error: You are muted by an admin.");
    if(agctog != 0){
        if(gctog[playerid] != 0){
            if(gctag[playerid] != 0){
                format(string, sizeof(string), "(Global Chat) %s [%s] (%d): %s", gctagname[playerid], pname(playerid), playerid, message);
                SendGlobalChat(string);
            }
            else{
                format(string, sizeof(string), "(Global Chat) %s (%d): %s", pname(playerid), playerid, message);
                SendGlobalChat(string);
            }
        } else {
            SendClientMessage(playerid, COLOR_ADMINS, "Error: You have disabled the global chat, /toggc to enable it.");
        }
    } else {
        SendClientMessage(playerid, COLOR_ADMINS, "Error: Global chat is disabled by an admin.");
    }
    return 1;
}
CMD:toggc(playerid, params[]){
    if(gctog[playerid] != 0){
        gctog[playerid] = 0;
        SendClientMessage(playerid, COLOR_WHITE1, "[!] You have disabled the global chat.");
    } else {
        gctog[playerid] = 1;
        SendClientMessage(playerid, COLOR_WHITE1, "[!] You have enabled the global chat.");
    }
    return 1;
}
CMD:setgtag(playerid, params[]){
    if(!IsPlayerAdmin(playerid)) return 0;
    new id, tag[30], string[128];
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, COLOR_WHITE1, "Usage: /setgtag [playerid] [tag]");
    if(!IsPlayerConnected(id)) return SendClientMessage(playerid, COLOR_ADMINS, "Error: Invalid player id.");
    if(sscanf(params, "ds", id, tag))
    {
        if(gctag[id] == 1){
            SendClientMessage(id, COLOR_ADMINS, "[AdmCmd]: An admin has removed your global chat tag.");
            gctag[id] = 0;
            gctagname[id] = "None";
            format(string, sizeof(string), "[AdmCmd]: You have removed %s's global chat tag.", pname(id));
            SendClientMessage(playerid, COLOR_ADMINS, string);
        } else if(gctag[id] == 0) {
            SendClientMessage(playerid, COLOR_ADMINS, "Error: That player doesn't have any global chat tag.");
        }
    } else {
        format(string, sizeof(string), "[AdmCmd]: An admin has set your global chat tag to \"%s\".", tag);
        SendClientMessage(id, COLOR_ADMINS, string);
        gctag[id] = 1;
        gctagname[id] = tag;
        format(string, sizeof(string), "[AdmCmd]: You have set %s's global tag to \"%s\".", pname(id), tag);
        SendClientMessage(playerid, COLOR_ADMINS, string);
    }
    return 1;
}
CMD:atoggc(playerid, params[]){
    if(!IsPlayerAdmin(playerid)) return 0;
    if(agctog != 0){
        agctog = 0;
        SendClientMessageToAll(COLOR_ADMINS, "[AdmCmd]: An admin has disabled global chat.");
    } else {
        agctog = 1;
        SendClientMessageToAll(COLOR_ADMINS, "[AdmCmd]: An admin has enabled global chat.");
    }
    return 1;
}
SendGlobalChat(message[]){
    for (new i = 0; i < MAX_PLAYERS; i++) {
        if (IsPlayerConnected(i) && gctog[i] != 0) SendClientMessage(i, 0xFF9B00FF, message);
    }
}
forward gunmuteplayertimer(playerid);
public gunmuteplayertimer(playerid){
    foreach(new i: Player){
        if(gcunmutetimer[i] != 0){
            gcmutetimer[i] --;
        } else{
            TimeGcUnmute(i);
        }
    }
    return 1;
}
forward TimeGcUnmute(playerid);
public TimeGcUnmute(playerid){
    new string[256];
    gcmutetimer[playerid] = 0;
    gcmute[playerid] = 0;
    format(string, sizeof(string), "[System]: You have been automatically unmuted after serving your duration.");
    SendClientMessage(playerid, COLOR_ADMINS, string);
    return 1;
}
stock pname(playerid)
{
	new playname[MAX_PLAYER_NAME];
	GetPlayerName(playerid, playname, MAX_PLAYER_NAME);
	return playname;
}
