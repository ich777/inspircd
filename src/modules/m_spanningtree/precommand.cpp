/*
 * InspIRCd -- Internet Relay Chat Daemon
 *
 *   Copyright (C) 2008 Thomas Stagner <aquanight@inspircd.org>
 *   Copyright (C) 2007 Craig Edwards <craigedwards@brainbox.cc>
 *
 * This file is part of InspIRCd.  InspIRCd is free software: you can
 * redistribute it and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation, version 2.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "inspircd.h"

#include "main.h"

/* $ModDep: m_spanningtree/main.h */

ModResult ModuleSpanningTree::OnPreCommand(std::string &command, std::vector<std::string>& parameters, LocalUser *user, bool validated, const std::string &original_line)
{
	/* If the command doesnt appear to be valid, we dont want to mess with it. */
	if (!validated)
		return MOD_RES_PASSTHRU;

	if (command == "CONNECT")
	{
		return this->HandleConnect(parameters,user);
	}
	else if (command == "SQUIT")
	{
		return this->HandleSquit(parameters,user);
	}
	else if (command == "MAP")
	{
		return this->HandleMap(parameters,user) ? MOD_RES_DENY : MOD_RES_PASSTHRU;
	}
	else if (command == "LINKS")
	{
		this->HandleLinks(parameters,user);
		return MOD_RES_DENY;
	}
	else if (command == "WHOIS")
	{
		if (parameters.size() > 1)
		{
			// remote whois
			return this->HandleRemoteWhois(parameters,user);
		}
	}
	else if ((command == "VERSION") && (parameters.size() > 0))
	{
		return this->HandleVersion(parameters,user);
	}
	return MOD_RES_PASSTHRU;
}

