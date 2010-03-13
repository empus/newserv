#ifndef __CHANSERV_MESSAGES_H
#define __CHANSERV_MESSAGES_H

#define Q9_FORMAT_TIME "%d/%m/%y %H:%M GMT"
#define TIMELEN 30

#define Q9_LOG_FORMAT_TIME "%d/%m/%y %H:%M:%S"

#define MAXMESSAGES  250

#ifdef COMPILING_MESSAGES
#define msg(token, message, args) message, args
#define BeginMessages() char *defaultmessages[MAXMESSAGES*2] =
#define EndMessages();
#else
#define msg(token, message, argsx) token
#define BeginMessages(x) typedef enum csrawmessages
#define EndMessages() csrawmessages; extern char *defaultmessages[MAXMESSAGES*2];
#endif

BeginMessages() {
  msg(QM_PROTECTED, "Channel $0 is protected by $1.", "ss"),
  msg(QM_UNKNOWNCMD, "Unknown command $0. Type SHOWCOMMANDS for a list of available commands.", "s"),
  msg(QM_SECUREONLY, "To prevent sensitive information being accidentally send to malicious users\non other networks, when using the $0 command, you must use\n/msg $1@$2.", "sss"),
  msg(QM_AUTHEDONLY, "$0 is only available to authed users. Try AUTH to authenticate with your\naccount, or HELLO to create an account.", "s"),
  msg(QM_UNAUTHEDONLY, "$0 is not available once you have authed.", "s"),
  msg(QM_COMMANDLIST, "The following commands are available to you.\nFor more information on a specific command, type HELP <command>:", ""),
  msg(QM_ENDOFLIST, "End of list.", ""),
  msg(QM_DONE, "Done.", ""),
  msg(QM_NOTENOUGHPARAMS, "You didn't provide enough parameters for $0.", "s"),
  msg(QM_UNKNOWNCHAN, "Channel $0 is unknown or suspended.", "s"),
  msg(QM_NOACCESSONCHAN, "You do not have sufficient access on $0 to use $1.", "ss"),
  msg(QM_CURCHANFLAGS, "Current channel flags for $0: $1", "ss"),
  msg(QM_CURFORCEMODES, "Current forced modes on $0: $1", "ss"),
  msg(QM_NOACCESS, "You do not have sufficient privileges to use $0.", "s"),
  msg(QM_UNKNOWNUSER, "Can't find user $0.", "s"),
  msg(QM_USERNOTAUTHED, "User $0 is not authed.", "s"),
  msg(QM_CHANLEVHEADER, "Known users on $0:", "s"),
  msg(QM_CHANLEVCOLSHORT, "Username        Flags", ""),
  msg(QM_CHANLEVCOLFULL, "Username        Flags         Last join       Last changed    ", ""),
  msg(QM_NOUSERSONCHANLEV, "No known users found on $0.", "s"),
  msg(QM_CHANUSERFLAGS, "Flags for $0 on $1: $2", "sss"),
  msg(QM_CHANUSERUNKNOWN, "User $0 is not known on $1.", "ss"),
  msg(QM_INVALIDCHANLEVCHANGE, "Invalid or disallowed flag specified.", ""),
  msg(QM_USERISAUTHEDAS, "$0 is authed as $1.", "ss"),
  msg(QM_USERISSTAFF,  "QuakeNet Staff : Staff Member", ""),
  msg(QM_USERISHELPER, "QuakeNet Staff : IRC Support", ""),
  msg(QM_USERISOPER,   "QuakeNet Staff : IRC Operator", ""),
  msg(QM_USERISADMIN,  "QuakeNet Staff : IRC Administrator", ""),
  msg(QM_USERISDEV,    "QuakeNet Staff : Developer", ""),
  msg(QM_WHOISHEADER, "$0 is known on the following channels:", "s"),
  msg(QM_WHOISCOLS, "Channel                        Flags", ""),
  msg(QM_USERONNOCHANS, "$0 is not known on any channels.", "s"),
  msg(QM_CHANAUTOLIMIT, "Current autolimit setting on $0: $1", "sd"),
  msg(QM_CHANBANAUTOREMOVE, "Bans on $0 will be removed after: $1", "ss"),
  msg(QM_NOCHANBANAUTOREMOVE, "Bans on $0 will not be automatically removed.", "s"),
  msg(QM_INVALIDCHANNAME, "$0 is not a valid channel name.", "s"),
  msg(QM_ALREADYREGISTERED, "$0 is already registered.", "s"),
  msg(QM_CURUSERFLAGS, "User flags for $0: $1", "ss"),
  msg(QM_WELCOMEMESSAGEIS, "Welcome message for $0: $1", "ss"),
  msg(QM_GLOBALINFO, "Default info line: $0", "s"),
  msg(QM_CHANNELINFO, "Info line on $0: $1", "ss"),
  msg(QM_PROTECTEDNICK, "$0 is a protected helper or oper nick. Please use a different nickname.", "s"),
  msg(QM_NICKWASFAKED, "I created a fakeuser $0 to prevent your nick being stolen.", "s"),
  msg(QM_NOTPROTECTED, "Sorry, your nick $0 is not protected.", "s"),
  msg(QM_SAMEAUTH, "$0 is authed as $1. Cannot reclaim nick.", "ss"),
  msg(QM_AUTHFAIL, "Username or password incorrect.", ""),
  msg(QM_AUTHOK, "You are now logged in as $0.\nRemember: NO-ONE from QuakeNet will ever ask for your password.  NEVER send your password to ANYONE except Q@CServe.quakenet.org.", "s"),
  msg(QM_NEWACCOUNT, "Account $0 created successfully.\nInformation about how to access and use your new account will be sent to your email address, $1.\nIf you do not see an email soon be sure to check your spam folder.", "ss"),
  msg(QM_AUTHNAMEINUSE, "Someone already has the account name $0!\nIf this is your account use AUTH to login, otherwise please change your nick using /NICK and try again.", "s"),
  msg(QM_ALREADYONCHAN, "You're already on $0.", "s"),
  msg(QM_NOTONCHAN, "You're not on $0.", "s"),
  msg(QM_ALREADYOPPED, "You're already opped on $0.", "s"),
  msg(QM_USERNOTONCHAN, "$0 is not on $1.", "ss"),
  msg(QM_USEROPPEDONCHAN, "$0 is already opped on $1.", "ss"),
  msg(QM_CANTOP, "Channel settings prevent $0 being opped on $1.", "ss"),
  msg(QM_NOTOPPED, "You're not opped on $0.", "s"),
  msg(QM_ALREADYVOICED, "You're already voiced on $0.", "s"),
  msg(QM_NOTVOICED, "You're not voiced on $0.", "s"),
  msg(QM_USERVOICEDONCHAN, "$0 is already voiced on $1.", "ss"),
  msg(QM_REGBANHEADER, "Registered bans on $0:\nID  Hostmask                      Expires            Set by           Reason", "s"),
  msg(QM_NOBANS, "No bans on $0.", "s"),
  msg(QM_REMOVEDCHANBAN, "Removed channel ban $0 from $1.", "ss"),
  msg(QM_NOTREMOVEDPERMBAN, "You need the master flag to remove registered ban $0 from $1.", "ss"),
  msg(QM_REMOVEDPERMBAN, "Removed registered ban $0 from $1.", "ss"),
  msg(QM_CANTVOICE, "Channel settings prevent $0 being voiced on $1.", "ss"),
  msg(QM_NOHELP, "Sorry, no help available for $0.", "s"),
  msg(QM_WHOISHEADER_NICK, "-Information for user $0 (using account $1):", "ss"),
  msg(QM_WHOISHEADER_AUTH, "-Information for account $0:", "s"),
  msg(QM_WHOIS_USERS, "Account users  : $0", "s"),
  msg(QM_WHOIS_LASTAUTH, "Last auth      : $0", "s"),
  msg(QM_WHOIS_LASTUSERHOST, "Last user@host : $0", "s"),
  msg(QM_WHOIS_USERID, "User ID        : $0", "d"),
  msg(QM_WHOIS_INFO, "Info           : $0", "s"),
  msg(QM_WHOIS_COMMENT, "Staff comment  : $0", "s"),
  msg(QM_WHOIS_FLAGS, "User flags     : $0", "s"),
  msg(QM_WHOIS_CREATED, "User created   : $0", "T"),
  msg(QM_WHOIS_CHANHEADER, "Known on the following channels:\nChannel                        Flags", ""),
  msg(QM_WHOIS_EMAIL, "Email address  : $0", "s"),
  msg(QM_WHOIS_EMAILSET, "Email last set : $0", "T"),
  msg(QM_COMMENT, "Staff comment for $0: $1.", "ss"),
  msg(QM_NOCOMMENT, "No staff comment for $0.", "s"),
  msg(QM_BADAUTH, "$0: Your account has been deleted or suspended.", "s"),
  msg(QM_USERHASBADAUTH, "Account $0 has been deleted.", "s"),
  msg(QM_BADEMAIL, "Sorry, no accounts have that email address.", ""),
  msg(QM_MAILTHROTTLED, "Sorry, but you have already requested a password. You will have to wait atleast $0 hours, before requesting again.", "g"),
  msg(QM_MAILQUEUED, "Mail queued for delivery", ""),
  msg(QM_PWDONTMATCH, "Sorry, but passwords do not match", ""),
  msg(QM_PWTOSHORT, "Sorry, but new password is to short", ""),
  msg(QM_PWCHANGED, "Ok, password changed", ""),
  msg(QM_INVALIDDURATION2, "Duration too long or invalid: $0", "s"),
  msg(QM_EMAILCHANGED, "Ok, email changed to \"$0\"", "s"),
  msg(QM_EMAILDONTMATCH, "Sorry, but first and second email addresses don't match", ""),
  msg(QM_INVALIDEMAIL, "$0 is not a valid email address", "s"),
  msg(QM_EMAILTOOSHORT, "Email ($0) too short", "s"),
  msg(QM_NOTYOUREMAIL, "\"$0\" is not your email address", "s"),
  msg(QM_EMAILNOAT, "Email ($0) must contain at least one at sign (@)", "s"),
  msg(QM_EMAILATEND, "Email ($0) can't end with an at sign (@)", "s"),
  msg(QM_EMAILINVCHR, "Email ($0) contains invalid characters", "s"),
  msg(QM_CHANNELNOTSUSPENDED, "Channel $0 is not suspended.", "s"),
  msg(QM_CHANNELALREADYSUSPENDED, "Channel $0 is already suspended.", "s"),
  msg(QM_CHANTYPE, "Channel type: $0", "s"),
  msg(QM_UNKNOWNCHANTYPE, "$0: unknown channel type", "s"),
  msg(QM_FOUNDER, "Original founder: $0", "s"),
  msg(QM_ADDEDBY, "Added by: $0", "s"),
  msg(QM_ALREADYKNOWNONCHAN, "$0 is already known on $1.", "ss"),
  msg(QM_CANNOTREMOVEOWNER, "Not removing channel owner $0 from $1.", "ss"),
  msg(QM_CANNOTREMOVEMASTER, "Not removing channel master $0 from $1.", "ss"),
  msg(QM_UNKNOWNBAN, "Can't find ban $0 on $1.", "ss"),
  msg(QM_YOURLANGUAGE, "Your language is currently set to: $0.", "s"),
  msg(QM_LANGUAGELIST, "The following languages are currently known:", ""),
  msg(QM_UNKNOWNLANGUAGE, "Unknown language code: $0.", "s"),
  msg(QM_WHOIS_USERLANG, "Language       : $0", "s"),
  msg(QM_CHANTYPEIS, "Channel type for $0 is: $1", "ss"),
  msg(QM_STATSHEADER, "Statistics for $0:", "s"),
  msg(QM_STATSADDED, "Date added: $0", "T"),
  msg(QM_STATSJOINS, "Since $0: maximum size $1, $2 joins ($3 joins/day).", "Tddg"),
  msg(QM_STATSLASTACTIVE, "Last active: $0", "T"),
  msg(QM_AUTHSUSPENDED, "Your Q account is suspended.", ""),
  msg(QM_REASON, "Reason: $0", "s"),
  msg(QM_EXPIRES, "Expires: $0", "T"),
  msg(QM_TOOMANYAUTHS, "Too many users AUTH'd to this account.", ""),
  msg(QM_INVALIDDURATION, "Duration must be between 1d and 1M.", ""),
  msg(QM_DISCONNECTINGUSER, "Disconnecting $0 (authed as $1)", "ss"),
  msg(QM_USERALREADYSUSPENDED, "User is already suspended.", ""),
  msg(QM_USERNOTSUSPENDED, "User $0 is not suspended.", "s"),
  msg(QM_SPEWHEADER, "Username:       Suspended: Email:                         Last auth:      Last user@host:", ""),
  msg(QM_TOOMANYRESULTS, "Found over $0 $1, truncating list.", "ds"),
  msg(QM_RESULTCOUNT, "Found $0 $1$2.", "uss"),
  msg(QM_SUSPENDKILL, "Attention: Your Q account has been suspended. You are being disconnected.", ""),
  msg(QM_LISTFLAGSHEADER, "Username:       Flags:            Suspended: Email:                         Last user@host:", ""),
  msg(QM_SUSPENDUSERLISTHEADER, "Username:       Suspend type: Suspended by:   Date suspended:     Expires:        Reason:", ""), /* @TIMELEN */
  msg(QM_SUSPENDCHANLISTHEADER, "Channel:                       Suspended by:   Date suspended:     Reason:", ""), /* @TIMELEN */
  msg(QM_NOREQUESTOWNER, "You cannot request ownership of $0 as there is a channel $1 present.", "ss"),
  msg(QM_GRANTEDOWNER, "You have been granted ownership of $0.", "s"),
  msg(QM_AUTHHISTORYHEADER, "#:  User:                                              Authed:             Disconnected:       Reason:", ""), /* @TIMELEN */
  msg(QM_CURDOMAINMODES, "Current modes on $0: $1", "ss"),
  msg(QM_SPEWDOMAINHEADER, "Domain:             Users:  Flags:", ""),
  msg(QM_DOMAINLIMIT, "Sorry, no more accounts are allowed from this email domain.", ""),
  msg(QM_PWTOWEAK, "Password too weak - You need to avoid repeating characters, and have different character types (e.g. 1 number and 1 letter)", ""),
  msg(QM_GIVEOWNERNOTMASTER, "User $0 is not a master on $1 - you must promote user to master status first.", "ss"),
  msg(QM_GIVEOWNERALREADYOWNER, "User $0 is already an owner on $1.", "ss"),
  msg(QM_GIVEOWNERNEEDHASH, "WARNING: This command will give COMPLETE control over $0 to $1,\nincluding the ability to remove you as owner. If you are sure you want to\ndo this, type: GIVEOWNER $2 #$3 $4", "sssss"),
  msg(QM_GIVEOWNERWRONGHASH, "Hash value incorrect, try again.", ""),
  msg(QM_SHOWINGDURATION, "Showing $0 for last $1.", "ss"),
  msg(QM_INVALIDACCOUNTNAME, "Change your nickname to something with none of the following characters: `~^[]{}|_\\", ""),
  msg(QM_CHALLENGEBADALGORITHM, "Invalid digest algorithm.", ""),
  msg(QM_NOCHALLENGE, "Challenge has either not been requested or has expired.", ""),
  msg(QM_USEGIVEOWNER, "For security reasons it is not possible to give the owner flag to other users\nusing CHANLEV. Use GIVEOWNER if you really wanted to do this.", ""),
  msg(QM_NOFLAGSPECIFIED, "You must specify at least one valid flag to add.", ""),
  msg(QM_NEWBANALREADYBANNED, "New ban is already contained within existing ban: $0", "s"),
  msg(QM_NEWBANOVERLAPS, "New ban would replace at least one existing ban ($0), use UNBANMASK $1 first if you want to set this ban.", "ss"),
  msg(QM_REPLACINGTEMPBAN, "A temporary ban with this mask already exists, replacing it.", ""),
  msg(QM_PERMBANALREADYSET, "That permanent ban already exists.", ""),
  msg(QM_NOTREPLACINGBANLDURATION, "That ban is already set with a longer duration.", ""),
  msg(QM_REPLACINGBANSDURATION, "Replaced existing ban which was set with a shorter duration.", ""),
  msg(QM_TOOMANYCHANLEVS, "Channel has too many user entries, aborting.", ""),
  msg(QM_TOOMANYBANS, "No more bans are allowed on that channel.", ""),
  msg(QM_WARNNOTREMOVEDPERMBAN, "Warning: not removing registered ban $0 from $1.", "ss"),
  msg(QM_MAXHELLOLIMIT, "Sorry, the registration service is unavailable to you at this time. Please try again later.", ""),
  msg(QM_ADDRESSLIMIT, "Too many accounts exist from this email address.", ""),
  msg(UNUSED_1, "", ""),
  msg(QM_TYPEHELPFORHELP, "For more information, type HELP $0.", "s"),
  msg(QM_REQUESTPASSPRIVUSER, "Cannot send password for that account.", ""),
  msg(QM_EMAILMATCHESOLD, "The new email address is the same as current one.", ""),
  msg(QM_INVALIDLIMIT, "Supplied autolimit is invalid: $0", "s"),
  msg(QM_ACCOUNTLOCKED, "This account has recently been modified. It will be unlocked on $0.", "T"),
  msg(QM_ACCOUNTNOTLOCKED, "That account is not locked.", ""),
  msg(QM_RESETOK, "Your old account settings have been restored, please check your email.", ""),
  msg(QM_BADRESETCODE, "Bad reset code.", ""),
  msg(QM_CHALLENGEDDEPRECATED, "WARNING: the selected algorithm is legacy functionality and is likely to be removed in the near future.", ""),
  msg(QM_CHANLEVSUMMARY, "Total: $0 (owner: $1, master: $2, op: $3, voice: $4, known: $5, ban: $6).", "ddddddd"),
  msg(QM_MAILLOCKHEADER, "Pattern:                                           Created by:     Reason:                   Created:", ""),
  msg(QM_MAILLOCKDOESNTEXIST, "That pattern doesn't exist.", ""),
  msg(QM_MAILLOCKALREADYEXISTS, "That pattern already exists!", ""),
  msg(QM_MAILLOCKED, "Sorry, you can't use that email address.", ""),
  msg(QM_NOACCESSONUSER, "You do not have sufficient access to use $0 on $1.", "ss"),
  msg(QM_NOCHANOPHISTORY, "No channel op events have been logged for $0.", "s"),
  msg(QM_CHANOPHISTORYHEADER, "Channel op events on $0:\nNickname        Account used", "s"),
  msg(QM_OTHERUSERAUTHEDLIMIT, "Warning: $0 ($1@$2) attempted to auth with your password but you already had $3 users authed to your account.", "sssd"),
  msg(QM_OTHERUSERAUTHED, "Warning: $0 ($1@$2) authed with your password.", "sss"),
  msg(QM_STATSRESET, "Resettable statistics reset for $0.", "s"),
  msg(QM_CHANLEVEMPTIEDCHANNEL, "The channel has been deleted since the last known user was removed.", ""),
  msg(QM_CHANLEVCHANGED, "Done. Flags for $0 on $1 are now: $2.", "sss"),
  msg(QM_CHANLEVREMOVED, "Done. User $0 is no longer known on $1.", "ss"),
  msg(QM_CHANLEVNOCHANGE, "Nothing changed. This could be because you specified an impossible flag combination or don't have enough access.", ""),
  msg(QM_USERSHEADER, "Users currently on $0:\nNick            Username        Flags        Host", "s"),
  msg(QM_EMPTYCHAN, "Channel $0 is currently empty.", "s"),
  msg(QM_USERSSUMMARY, "Total $0 users: $1 opped, $2 voiced, $3 others, $4 with flags ($5 ops, $6 masters)", "ddddddd"),
  msg(QM_OPERONCHAN, "You cannot use $0 on $1 since an oper is on the channel.","ss"),
  msg(QM_USERSUSPENDEDTYPE,   "Suspend type   : $0", "s"),
  msg(QM_USERSUSPENDEDBY,     "Suspended by   : $0", "s"),
  msg(QM_USERSUSPENDEDREASON, "Suspend reason : $0", "s"),
  msg(QM_USERSUSPENDEDAT,     "Suspended at   : $0", "T"),
  msg(QM_USERSUSPENDEDEXPIRY, "Suspend expiry : $0", "s"),
  msg(QM_INVALIDDOMAIN, "$0 is not a valid domain.", "s"),
  msg(QM_SHORT_COMMENT, "Staff comment: $0", "s"),
  msg(QM_CHANLEV_SUSPENDREASON, "Suspended: $0", "s"),
  msg(QM_CHANLEV_SUSPENDSINCE, "Suspended since: $0", "T"),
  msg(QM_CHANLEV_SUSPENDBY, "Suspended by: $0", "s"),
  msg(QM_TRUNCATED, "Warning: list truncated to $0 items.", "d"),
  msg(QM_WHOIS_PASSSET, "Pass last set  : $0", "T"),
  msg(QM_TICKETEXPIRED, "Sorry, you've taken too long to log in (ticket has expired).", ""),
  msg(QM_TICKETNOTYETVALID, "The supplied login credentials are not valid (ticket not yet valid).", ""),
  msg(QM_CONFIGURATIONERROR, "Configuration error, contact an IRC Operator.", ""),
  msg(QM_INVALIDHMAC, "The supplied login credentials are not valid (bad HMAC).", ""),
  msg(QM_PASSEMAILCHANGED, "Auth failed: account password has been changed since you logged in.", ""),
  msg(QM_REASONREQUIRED, "Supply a decent reason.", ""),
  msg(QM_BYPASSINGSUSPEND,"NOTE: $0 is suspended, bypassing suspension.", "s"),
  msg(QM_ACHIEVEMENTUNLOCKED,"ACHIEVEMENT UNLOCKED: [$1] $0","sd"),
  msg(QM_ACHIEVEMENTLISTHEADER,"User $0 has unlocked the following achievements:","s"),
  msg(QM_ACHIEVEMENTLISTMEHEADER,"You have unlocked the following achievements:",""),
  msg(QM_ACHIEVEMENTLISTEND,"End of list ($0 total achievement points).","d"),
  msg(QM_NOACHIEVEMENTS,"User $0 does not have any achievements yet.","s"),
  msg(QM_ACHIEVEMENTCOMPARETIE,"End of list.  It's a tie!",""),
  msg(QM_ACHIEVEMENTCOMPARERESULT,"End of list.  User $0 is ahead by $1 points!", "sd"),
} 
EndMessages()
#endif
