//
// Copyright (c) 2008-2013 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#pragma once
#include "Object.h"
#include "Context.h"
#include "Ptr.h"
#include "List.h"
#include "HashMap.h"
#include "StateManager.h"
#include "UIElement.h"
#include "Sprite.h"
#include "Node.h"
#include "Scene.h"
#include "Text.h"
#include "ExpirationTimer.h"

// All Urho3D classes reside in namespace Urho3D
using namespace Urho3D;



//-----------------------------------------------------------------------------
// State
//-----------------------------------------------------------------------------
class SplashState : public State
{
	// Enable type information.
	OBJECT(SplashState);


public:

	//-------------------------------------------------------------------------
	// Constructor & Destructor
	//-------------------------------------------------------------------------
	SplashState(Context* context);
	~SplashState();

	//-------------------------------------------------------------------------
	// Public Virtual Methods
	//-------------------------------------------------------------------------
	// State Activation
	/// Init is called directly after state is registered 
	virtual bool	Initialize();
	virtual bool	Begin();
	/// after end : We are no longer attached to anything (simply being stored in
	///				the registered state list maintained by the manager).
	virtual void	End();

	/// Handle the logic update event.
	void HandleUpdate(StringHash eventType, VariantMap& eventData);

	void SetNextState(const char* id);
protected:
	//-------------------------------------------------------------------------
	// Protected Variables
	//-------------------------------------------------------------------------
	/// The UI's root UIElement.
	SharedPtr<UIElement> uiRoot_;
	SharedPtr<Sprite> backgroundSprite_;
	ExpirationTimer timer_;
	bool active_;
	String nextStateID_;
};
