// Fill out your copyright notice in the Description page of Project Settings.
//�e��
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class USoundBase;

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	UStaticMeshComponent *ProjectileMesh;

	UPROPERTY(VisibleAnyWhere, Category = "Movement")
	class UProjectileMovementComponent *ProjectileMovementComponent;

	UFUNCTION()
	void OnHit(UPrimitiveComponent *HitComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &Hit);

	UPROPERTY(EditAnywhere)
		float Damage = 50.f;

	UPROPERTY(EditAnywhere, Category = "Combat")
		class UParticleSystem* HitParticles;

	UPROPERTY(VisibleAnyWhere, Category = "Combat")
		class UParticleSystemComponent* TrailParticles;

	UPROPERTY(EditAnywhere, Category = "Combat")
		USoundBase* LaunchSound;

	UPROPERTY(EditAnywhere, Category = "Combat")
		USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category = "Combat")
		TSubclassOf<class UCameraShakeBase> HitCameraShakeClass;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};