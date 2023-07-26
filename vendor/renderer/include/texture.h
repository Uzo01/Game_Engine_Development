/* \file texture.h */
#pragma once

#include <inttypes.h>
#include <memory>
#include <glm/glm.hpp>

namespace IMAT3905
{
	/** \class Texture
	* \brief Class used to load textures from file using STBimage
	*/
	class Texture
	{
	public:
		Texture(const char* filepath); //!< Constructor with file path
		Texture(uint32_t width, uint32_t height, uint32_t channels, unsigned char* data); //!< Constructor with raw data
		~Texture(); //!< Destructor
		inline uint32_t getID() const { return m_OpenGL_ID; } //!< Returns the GL tetxure ID
		inline uint32_t getWidth() const  { return m_width; } //!< Returns the width of the texture
		inline uint32_t getHeight() const { return m_height; } //!< Returns the height of the texture
		inline float getWidthf()  const { return static_cast<float>(m_width); } //!< Returns the width of the texture as a float
		inline float getHeightf() const { return static_cast<float>(m_height); } //!< Returns the height of the texture as a float
		virtual inline uint32_t const getChannels() { return m_channels; } //!< Returns the channel count for the texture
	private:
		uint32_t m_OpenGL_ID; //!< Internal GL ID
		uint32_t m_width; //!< Internal width
		uint32_t m_height; //!< Internal height 
		uint32_t m_channels; //!< Internal channel count
		void init(uint32_t width, uint32_t height, uint32_t channels, unsigned char* data); //!< Internal texture initialisation
	};

	/** \class SubTexture
**  \brief A part of texture complete with size and UV co-ords. Does not hold texels!
*/

	class SubTexture
	{
	public:
		SubTexture(Texture& texture, const glm::vec2& UVStart, const glm::vec2& UVEnd); //!< Constructor with stuff
		SubTexture(Texture& texture, const glm::ivec2& pixelStart, const glm::ivec2& pixelEnd); //!< Constructor with stuff

		inline glm::vec2 getUVStart() const { return m_UVStart; } //!< Get the start UV co-ords
		inline glm::vec2 getUVEnd()	  const { return m_UVEnd; } //!< Get the end UV co-ords
		glm::ivec2 getSize() const { return m_size; } //!< Get the size of the subtexture 
		glm::vec2 getSizef() const { return { static_cast<float>(m_size.x), static_cast<float>(m_size.y) }; } //!< Get the size of the subtexture  as float
		inline uint32_t getWidth()   const { return m_size.x; } //!< Get the width of the subtexture 
		inline uint32_t getHeight()  const { return m_size.y; } //!< Get the height of the subtexture 
		inline uint32_t getWidthf()  const { return static_cast<float>(m_size.x); } //!< Get the width of the subtexture as a float
		inline uint32_t getHeightf() const { return static_cast<float>(m_size.y); } //!< Get the height of the subtexture as a float
		float transformU(float U); //!< Transform original to atlased co-ords - U component
		float transformV(float V); //!< Transform original to atlased co-ords - V component
		glm::vec2 transformUV(glm::vec2 UV); //!< Transform original to atlased co-ords
		inline Texture& getBaseTexture() const { return m_texture; } //!, Get the base texture
	private:
		Texture& m_texture; //!< base texture
		glm::vec2 m_UVStart; //!< start UV co-ords
		glm::vec2 m_UVEnd; //!< end UV co-ords
		glm::ivec2 m_size; //!< Size in pixels
	};
}
