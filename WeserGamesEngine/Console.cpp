#include "pch.h"

std::string Console::GetPrefix(const std::string& prefixname)
{
    std::time_t now = std::time(nullptr);
    std::tm timeinfo;
    localtime_s(&timeinfo, &now);
    std::stringstream ss;
    ss << std::put_time(&timeinfo, "%d/%m/%Y %H:%M:%S:%MS");
    std::string formattedTime = ss.str();
    std::string prefixnameUpperCase = prefixname;
    std::transform(prefixnameUpperCase.begin(), prefixnameUpperCase.end(), prefixnameUpperCase.begin(), ::toupper);
    std::string prefix = formattedTime + " [" + prefixnameUpperCase + "]";
    return prefix;
}

void Console::Log(const std::string& data)
{
    std::cout << Console::GetPrefix("info") << ": " << data << std::endl;
}

void Console::LogError(const std::string& data)
{
    std::cerr << Console::GetPrefix("error") << ": " << data << std::endl;
}

void Console::LogWarning(const std::string& data)
{
    std::cout << Console::GetPrefix("warn") << ": " << data << std::endl;
}

void Console::LogException(const std::exception& data)
{
    std::cerr << Console::GetPrefix("exception") << ": " << data.what()  << std::endl;
}
