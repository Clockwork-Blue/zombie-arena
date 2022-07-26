#include "TextureHolder.h"
#include <assert.h>

TextureHolder* TextureHolder::m_s_Instance = nullptr;
TextureHolder::TextureHolder()
{
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

Texture& TextureHolder::GetTexture(const std::string& filename) 
{
	//Get a referance to m_Texture using m_s_Texture
	auto& m = m_s_Instance->m_Textures;
	/*
	auto is equivilant to map<string, texture>
	create a iterator to hold a key-value pair (kvp)
	and search for required kvp
	using the passed in filename
	*/
	auto keyValuePair = m.find(filename);
	//in this case auto is equivalent to map<string, texture>::iterator
	//did we find a match
	if (keyValuePair != m.end())
	{
		/*
		Yes
		return the second part of the key value pair(texture)
		*/
		return keyValuePair->second;
	}
	else
	{
		/*
		 File name not found
		 Create a new key value pair using the filename
		 */
		auto& texture = m[filename];
		texture.loadFromFile(filename);
		return texture;
	}

}