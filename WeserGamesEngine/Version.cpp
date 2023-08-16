#include "Version.h"

Version::Version(int major) : major(&major), minor(nullptr), build(nullptr), patch(nullptr)
{
}

Version::Version(int major, int minor) : major(&major), minor(&minor), build(nullptr), patch(nullptr)
{
}

Version::Version(int major, int minor, int build) : major(&major), minor(&minor), build(&build), patch(nullptr)
{
}

Version::Version(int major, int minor, int build, int patch) : major(&major), minor(&minor), build(&build), patch(&patch)
{
}

Version::~Version()
{
	delete major, minor, build, patch;
}

int* Version::GetMajor()
{
	return major;
}

int* Version::GetMinor()
{
	return minor;
}

int* Version::GetBuild()
{
	return build;
}

int* Version::GetPatch()
{
	return patch;
}

string Version::toString()
{
    stringstream ss;
    if (major)
        ss << &major;
    else
        ss << "0";

    ss << ".";

    if (minor)
        ss << &minor;
    else
        ss << "0";

    if (build || patch)
    {
        ss << ".";
        if (build)
            ss << &build;
        else
            ss << "0";

        if (patch)
            ss << "." << &patch;
    }
    return ss.str();
}
