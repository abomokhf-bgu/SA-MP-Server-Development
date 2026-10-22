Hook:F_OnGameModeInit()
{
    //CreateDynamicActor(106, 2516.3745,-1676.1100,13.9699, 75.0);
    //CreateDynamicActor(104, 1995.1755,-1115.8999,26.7737, 180.0);
    Create3DTextLabel("{006f00}Grove Street\n{ffffff}Press Y to join the family.", 0x008080FF, 2521.31, -1678.48, 15.49, 40.0, 0, 1);
    Create3DTextLabel("{b01ac6}Glen Park Ballas\n{ffffff}Press Y to join the family.", 0x008080FF, 1995.76, -1115.67, 26.77, 40.0, 0, 1);
    //Create3DTextLabel("{F09186}\nPress Y to buy guns.", 0x008080FF, 2441.88, -1964.44, 13.54, 40.0, 0, 1); //emmet
    // 2441.88, -1964.44, 13.54 emmet
    return 1;
}


Hook:F_OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(PRESSED(KEY_YES))
    {
       if(IsPlayerInRangeOfPoint(playerid, 5.0, 2521.31, -1678.48, 15.49))
       {
             /*if(PlayerInfo[playerid][pMember] != 0 || PlayerInfo[playerid][pLeader] != 0) return SendClientMessage(playerid, COLOR_GREY, "You're already in a faction (/quitfaction) first.");
             if(PlayerInfo[playerid][pFMember] != 255) return SendClientMessage(playerid, COLOR_GREY, "You're already in a family (/quitfamily) first.");
             if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_GREY, "You can not be in a vehicle to do this.");
             PlayerInfo[playerid][pFMember] = 0;
             PlayerInfo[playerid][pRank] =1;
             FamilyInfo[PlayerInfo[playerid][pFMember]][FamilyMembers] ++;
             SaveFamilies();
             SendClientMessage(playerid, COLOR_LIGHTBLUE, "You've agreed to the family rules and joined Grove Street as Rank#1!");
             SendClientMessage(playerid, COLOR_GREY, "SERVER: Make sure you've read rules(/rules and /pointrules). Good Luck!");*/
             //if(PlayerInfo[playerid][pFMember] == 1) return SendClientMessage(playerid, COLOR_GREY, "You're already a member of Grove Street.");
			 if(PlayerInfo[playerid][pConnectTime] < 2) return SendClientMessage(playerid, COLOR_GREY, "You must play for at least 2 playing hours to join a public family.");
             if (PlayerInfo[playerid][pLevel] > 3) return SendClientMessage(playerid, COLOR_GREY, "You must be below level 4 to join a public family.");
             if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_GREY, "You can not be in a vehicle to do this.");
             if(PlayerInfo[playerid][pMember] != 0 || PlayerInfo[playerid][pLeader] != 0) return SendClientMessage(playerid, COLOR_GREY, "You're already in a faction (/quitfaction) first.");
             if(PlayerInfo[playerid][pFMember] != 255) return SendClientMessage(playerid, COLOR_GREY, "You're already in a family (/quitfamily) first.");
             ShowPlayerDialog(playerid, 3214, DIALOG_STYLE_MSGBOX, "Do you really want to join Grove Street?", "Are you sure? If so, press the (Yes) button, if no, press the (No) button.", "Yes", "No");
       }
       else if(IsPlayerInRangeOfPoint(playerid, 5.0, 1995.1755,-1115.8999,26.7737))
       {
             /*if(PlayerInfo[playerid][pMember] != 0 || PlayerInfo[playerid][pLeader] != 0) return SendClientMessage(playerid, COLOR_GREY, "You're already in a faction (/quitfaction) first.");
             if(PlayerInfo[playerid][pFMember] != 255) return SendClientMessage(playerid, COLOR_GREY, "You're already in a family (/quitfamily) first.");
             if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_GREY, "You can not be in a vehicle to do this.");
             PlayerInfo[playerid][pFMember] = 1;
             PlayerInfo[playerid][pRank] = 1;
             FamilyInfo[PlayerInfo[playerid][pFMember]][FamilyMembers] ++;
             SaveFamilies();
             SendClientMessage(playerid, COLOR_LIGHTBLUE, "You've agreed to the family rules and joined Front Yard Ballas as Rank#1!");
             SendClientMessage(playerid, COLOR_GREY, "SERVER: Make sure you've read rules(/rules and /pointrules). Good Luck!");*/
             //if(PlayerInfo[playerid][pFMember] = 2) return SendClientMessage(playerid, COLOR_GREY, "You're already a member of Glen Park Ballas.");
			 if(PlayerInfo[playerid][pConnectTime] < 2) return SendClientMessage(playerid, COLOR_GREY, "You must play for at least 2 playing hours to join a public family.");
             if (PlayerInfo[playerid][pLevel] > 3) return SendClientMessage(playerid, COLOR_GREY, "You must be below level 4 to join a public family.");
             if(IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_GREY, "You can not be in a vehicle to do this.");
             if(PlayerInfo[playerid][pMember] != 0 || PlayerInfo[playerid][pLeader] != 0) return SendClientMessage(playerid, COLOR_GREY, "You're already in a faction (/quitfaction) first.");
             if(PlayerInfo[playerid][pFMember] != 255) return SendClientMessage(playerid, COLOR_GREY, "You're already in a family (/quitfamily) first.");
             ShowPlayerDialog(playerid, 3215, DIALOG_STYLE_MSGBOX, "Do you really want to join Glen Park Ballas?", "Are you sure? If so, press the (Yes) button, if no, press the (No) button.", "Yes", "No");
       }
       return 1;
    }
    return 1;
}
Hook:fa_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
if(dialogid == 3214)
{
        if(!response)
        {
            SendClientMessage(playerid, COLOR_GREY, "Alright, so.. You do not want to join Grove Street.");
            return 1;
        }
        else
        {
                //new family = PlayerInfo[playerid][pFMember];
                //if(PlayerInfo[playerid][pFMember] == family) return SendClientMessage(playerid, COLOR_GREY, "You're already in Grove Street");
                PlayerInfo[playerid][pFMember] = 0;
                PlayerInfo[playerid][pRank] =1;
                FamilyInfo[PlayerInfo[playerid][pFMember]][FamilyMembers] ++;
                SaveFamilies();
                SendClientMessage(playerid, COLOR_LIGHTBLUE, "You've agreed to the family rules and joined Grove Street as Rank 1!");
                SendClientMessage(playerid, COLOR_GREY, "SERVER: Make sure you've read rules(/rules and /pointrules). Good Luck!");
                SetPlayerSkin(playerid, 106);
                return 1;
       }
}
if(dialogid == 3215)
{
          if(!response)
          {
              SendClientMessage(playerid, COLOR_GREY, "Alright, so.. You do not want to join Ballas..");
              return 1;
          }
          else
          {
                  PlayerInfo[playerid][pFMember] = 1;
                  PlayerInfo[playerid][pRank] = 1;
                  FamilyInfo[PlayerInfo[playerid][pFMember]][FamilyMembers] ++;
                  SaveFamilies();
                  SendClientMessage(playerid, COLOR_LIGHTBLUE, "You've agreed to the family rules and joined Glen Park Ballas as Rank 1!");
                  SendClientMessage(playerid, COLOR_GREY, "SERVER: Make sure you've read rules(/rules and /pointrules). Good Luck!");
                  SetPlayerSkin(playerid, 104);
                  return 1;
          }
}
return 1;
}
