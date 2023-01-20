#pragma once

namespace file {
	const char* read(const char* filename, bool& nameExists);

	void write(const char* text, const char* filename);

	void writel(const char* text, const char* filename);
}