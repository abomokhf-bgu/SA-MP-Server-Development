// Common Includes
// www.github.com/sporkyspork
// For Southland RP.


// Made this quickly without really thinking about the best way
// It should truncate a string nicely (whole words) and add trailing elipsis at the end if it was truncated
stock GetTruncatedString(str[])
{
    new returnstr[64];

    if (strlen(str) < 64)
    {
        strmid(returnstr, str, 0, 64);
        return returnstr;
    }

    new workingstr[60];
    strmid(workingstr, str, 0, sizeof(workingstr));
    
    new lastSpaceAt = 0;

    for (new c = 0; c < strlen(workingstr); c ++)
    {
        if (str[c] == ' ')
        {
            lastSpaceAt = c;
        }
    }

    if (lastSpaceAt != 0)
    {
        strmid(returnstr, workingstr, 0, lastSpaceAt);
    }

    strcat(returnstr, "...");
    return returnstr; 
}