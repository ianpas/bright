// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// Windows Header Files:
#define NOMINMAX
#include <windows.h>

#include <string>
#include <functional>
#include <memory>
#include <vector>
#include <mutex>
#include <algorithm>

#include <wrl.h>
#include <d2d1.h>
#pragma comment ( lib, "d2d1.lib" )

#include <DirectXMath.h>
#include <d3d11.h>
#pragma comment ( lib, "d3d11.lib" )

// TODO: reference additional headers your program requires here

#include "MeshManager.h"
#include "D2DManager.h"
#include "PipelineManager.h"
#include "GraphicsManager.h"


