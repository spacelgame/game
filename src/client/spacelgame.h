/*
 * This file is part of Spacel game.
 *
 * Copyright 2016, Loic Blot <loic.blot@unix-experience.fr>
 * Copyright 2016, Jeremy Lomoro <jeremy.lomoro@tuxsrv.fr>
 *
 * Spacel is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Spacel is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Spacel.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <Urho3D/Engine/Application.h>
#include <Urho3D/IO/Log.h>
#include <Urho3D/Resource/ResourceCache.h>

#include "mainmenu.h"
#include "settings.h"

using namespace Urho3D;

namespace spacel {

class MainMenu;

namespace engine {
	class Server;
}

enum GlobalUIId
{
	GLOBALUI_MAINMENU,
	GLOBALUI_LOADINGSCREEN,
};

class SpacelGame : public Application
{
	URHO3D_OBJECT(SpacelGame, Application);

public:
	SpacelGame(Context *context): Application(context) {}
	virtual void Setup();
	virtual void Start();
	virtual void Stop();

	void ChangeGameGlobalUI(const GlobalUIId ui_id, void *param = nullptr);
private:
	void InitLocales();

	ClientSettings *m_config = nullptr;
	engine::Server *m_server = nullptr;
};

}
