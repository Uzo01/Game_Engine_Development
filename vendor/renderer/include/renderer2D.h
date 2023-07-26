#pragma once

#include <vector>
#include <array>
#include <glm/glm.hpp>
#include "texture.h"

namespace IMAT3905
{
	/** \class Renderer2DVertex
*		\brief Definition of vertex used in the 2D renderer
*/
	class Renderer2DVertex
	{
	public:
		Renderer2DVertex() = default; //!< Default constructor
		Renderer2DVertex(const glm::vec4& pos, const glm::vec2& UVs, uint32_t tu, const glm::vec4& pTint) : //!< Constructor with stuff
			position(pos), uvCoords(UVs), texUnit(tu), tint(pTint) {}
		glm::vec4 position; //!< Vertex position (homogeneuous co-ords)
		glm::vec2 uvCoords; //!< UV cords
		glm::vec4 tint; //!< Tint applied to the vertex
		int32_t texUnit; //!< Tex unit for the texture
		int32_t entityID; //!< ID of the thing being drawn in any ECS
	};

/** \class Renderer2D
** \brief Class which allows the rendering of simple 2D primitives
*/
	class Renderer2D
	{
	public:
		static void init(uint32_t width, uint32_t height, uint32_t batchSize, const char* fontFilePath, uint32_t charSize); //!< Init the internal data of the renderer
		static void terminate(); //!< Clean up resources
		static void begin(const glm::mat4& cameraView, const glm::mat4& cameraProjection); //!< Begin a scene from cameras view

		static void submit(const glm::vec2& position, float angle, const glm::vec2& halfExtents, const glm::vec4& tint, int32_t entity_ID = -1, bool degrees = false); //!< Submit tint only
		static void submit(const glm::vec2& position, float angle, const glm::vec2& halfExtents, const Texture& texture, int32_t entity_ID = -1, bool degrees = false); //!< Submit texture only
		static void submit(const glm::vec2& position, float angle, const glm::vec2& halfExtents, const SubTexture& subTexture, int32_t entity_ID = -1, bool degrees = false); //!< Submit subtexture only
		static void submit(const glm::vec2& position, float angle, const glm::vec2& halfExtents, const Texture& texture, const glm::vec4& tint, int32_t entity_ID = -1, bool degrees = false); //!< Submit texture and tint
		static void submit(const glm::vec2& position, float angle, const glm::vec2& halfExtents, const SubTexture& subTexture, const glm::vec4& tint, int32_t entity_ID = -1, bool degrees = false); //!< Submit subtexture and tint

		static void submit(char ch, const glm::vec2& position, float& advance, const glm::vec4& tint); //!< Render a single character with a tint
		static void submit(const char* text, const glm::vec2& position, const glm::vec4& tint); //!< Render a single character with a tint
		
		static void end(); //!< Stop rendering a 2D scene
		static void flush(); //!< Flush the renderer

		static void onResize(const glm::ivec2& frameSize); //!< To be called when the OpenGL context is resized
		static int32_t getID(const glm::ivec2& pixel); //!< Get the ID for a given pixle. Does not check pixel bounds
		static void setClearColour(const glm::vec4& clearColour); //!< Set the clear colour for the screen
	private:

		static void newBatch(); //!< Prepare data for a new batch
		static void recreateFrameBuffer(const glm::ivec2& size); //!< Internal recreation of framebuffers
		
		/** \struct GlyphData
		\brief Data associated with a single glyph
		*/
		struct GlyphData
		{
			unsigned char ch;
			glm::vec2 size;
			glm::vec2 bearing;
			float advance;
			std::unique_ptr<SubTexture> subTexture;
		};
		
		/** \struct InternalData
		\brief Data held by the renderer
		*/
		struct InternalData
		{
			std::vector<Renderer2DVertex> vertices; //!< Space for vertex data
			glm::vec4 quad[4]; //!< Prototypical quad
			std::vector<uint32_t> boundTextures; //!< Texture ids bound to each texture
			std::array<int32_t,32> textureUnits = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31}; //!< List of texture units for passing to the GPU
			glm::vec4 defaultTint = glm::vec4(1.f); //!< Default tint - white
			uint32_t VAO_id; //!< GL id of VAO
			uint32_t VBO_id; //!< GL id of VBO
			uint32_t UBO_id; //!< GL id of UBO
			uint32_t program_id; //!< GL id of shader
			uint32_t defaultTexture_id; //!< GL id of default texture
			uint32_t batchSize; //!< Size of batches
			uint32_t drawCount; //!< Current draw count

			uint32_t FBO_id; //!< GL id of FBO
			uint32_t FBOColour1Texture_id; //!< GL id of FBO colour attachement 1 texture
			uint32_t FBOColour2Texture_id; //!< GL id of FBO colour attachement 2 texture
			uint32_t FBODepthTexture_id; //!< GL id of FBO depth attachement texture
			glm::ivec2 frameSize; //!< Current size of frame
			glm::mat4 FBOView; //!< View matrix for second pass
			glm::mat4 FBOProj; //!< Projection matrix for second pass
			glm::vec4 clearColour; //!< User set clear colour

			const unsigned char firstGlyph = 32; //!< First ASCII glyph
			const unsigned char lastGlyph = 126; //!< Last ASCII glyph
			std::array <GlyphData, 126 - 32 + 1> glyphData; //!< Glyphs data
			std::unique_ptr<Texture> glyphAtlas; //!< Glyph textures
			bool fontLoaded = false; //!< Has the font loaded correctly
		}; //!< Private data internal the renderer
	
		static std::unique_ptr<InternalData> s_data; //!< Internal data


	};
}