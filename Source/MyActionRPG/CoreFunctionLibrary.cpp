#include "CoreFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

FName UCoreFunctionLibrary::GetStreamingLevelNameFromActor(AActor* Actor)
{
	if (Actor)
	{
		if (ULevel* Level = Actor->GetLevel())
		{
			if (UObject* Outer = Level->GetOuter())
			{
				return Outer->GetFName();
			}
		}
	}

	return FName();
}
