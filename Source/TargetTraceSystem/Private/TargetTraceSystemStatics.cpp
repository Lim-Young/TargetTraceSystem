// Copyright Lim Young.


#include "TargetTraceSystemStatics.h"

FVector UTargetTraceSystemStatics::GetTargetPredictedLocation(const FVector& SourceLocation, const AActor* Actor,
	const float LeadTargetProjectileVelocity, const bool bLeadTargetIgnoreZVelocity)
{
	if (Actor == nullptr)
		return FVector::ZeroVector;

	const FVector FocusBaseLoc = Actor->GetActorLocation();

	if (LeadTargetProjectileVelocity > 0)
	{
		// Use simple first-order correction for deflection
		// This is not 100% accurate (doesn't even account for collision boxes) but is close enough; not being
		// perfect is a nice AI feature after all

		// We simply calculate the time it would take the projectile to hit the target where it is now, and calculate
		// where it will be in that time and aim at that instead
		const float TimeToHitCurrent = FVector::Distance(SourceLocation, FocusBaseLoc) /
			LeadTargetProjectileVelocity;
		FVector V = Actor->GetVelocity();
		if (bLeadTargetIgnoreZVelocity)
		{
			V.Z = 0;
			V.Normalize();
		}
		return FocusBaseLoc + FVector(TimeToHitCurrent) * Actor->GetVelocity();
	}

	return FocusBaseLoc;
}
