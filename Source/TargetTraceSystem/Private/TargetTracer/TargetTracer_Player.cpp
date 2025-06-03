// Copyright Lim Young.


#include "TargetTracer/TargetTracer_Player.h"

#include "Kismet/GameplayStatics.h"

FVector UTargetTracer_Player::Trace_Implementation(FTargetTracerContext& Context)
{
	const APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(Context.OwnerActor, 0);
	if (PlayerPawn == nullptr)
	{
		return FVector::ZeroVector;
	}

	return PlayerPawn->GetActorLocation();
}
