#include <appToOpen.h>
#include <jsonDecoder.h>

appToOpen::appToOpen():jsonLocation("../setting.json")
{
    json::jsonDecode(jsonLocation, appNames, appLocations);
}
