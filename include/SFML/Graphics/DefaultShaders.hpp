#ifndef SFML_DEFAULTSHADERS_HPP
#define SFML_DEFAULTSHADERS_HPP

#include <SFML/Graphics/Export.hpp>
#include <SFML/System/NonCopyable.hpp>

namespace sf
{
	class SFML_GRAPHICS_API DefaultShaders : NonCopyable
	{
		public:
			static void init();
			static void deinit();
	};
}

#endif
