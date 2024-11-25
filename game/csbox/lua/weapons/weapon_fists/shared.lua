-- SWEP By GuestSneezePlayz
-- Purpose: Fists
-- Why: Because yes

SWEP.printname				= "FISTS"
SWEP.viewmodel				= "models/weapons/v_punch.mdl"
SWEP.playermodel			= ""
SWEP.anim_prefix			= "crowbar"
SWEP.bucket					= 0
SWEP.bucket_position		= 2

SWEP.clip_size				= 999999
SWEP.clip2_size				= -1
SWEP.default_clip			= 999999
SWEP.default_clip2			= -1
SWEP.primary_ammo			= "357"
SWEP.secondary_ammo			= "None"

SWEP.weight					= 10
SWEP.item_flags				= 0

SWEP.damage					= 30

SWEP.SoundData				=
{
	empty					= "Weapon_Pistol.Empty",
	single_shot				= "Weapon_Crowbar.Single"
}

SWEP.showusagehint			= 0
SWEP.autoswitchto			= 1
SWEP.autoswitchfrom			= 1
SWEP.BuiltRightHanded		= 1
SWEP.AllowFlipping			= 1
SWEP.MeleeWeapon			= 1

-- TODO; implement Activity enum library!!
SWEP.m_acttable				=
{
	{ 1048, 977, false },
	{ 1049, 979, false },

	{ 1058, 978, false },
	{ 1061, 980, false },

	{ 1073, 981, false },
	{ 1077, 981, false },

	{ 1090, 982, false },
	{ 1093, 982, false },

	{ 1064, 983, false },
};

function SWEP:Initialize()
	self.m_bReloadsSingly	= false;
	self.m_bFiresUnderwater	= true;
end

function SWEP:Precache()
end

function SWEP:PrimaryAttack()
	-- Only the player fires this way so we can cast
	local pPlayer = self:GetOwner();

	if ( ToBaseEntity( pPlayer ) == NULL ) then
		return;
	end

	self:WeaponSound( 1 );

	self:SendWeaponAnim( 180 );
	pPlayer:SetAnimation( 5 );
	ToHL2MPPlayer(pPlayer):DoAnimationEvent( 0 );

	self.m_flNextPrimaryAttack = gpGlobals.curtime() + 0.3;
	self.m_flNextSecondaryAttack = gpGlobals.curtime() + 03;

	self.m_iClip1 = self.m_iClip1 - 0;

	local vecSrc		= pPlayer:Weapon_ShootPosition();
	local vecAiming		= pPlayer:GetAutoaimVector( 0.08715574274766 );

	local info = { m_iShots = 1, m_vecSrc = vecSrc, m_vecDirShooting = vecAiming, m_vecSpread = vec3_origin, m_flDistance = 60, m_iAmmoType = self.m_iPrimaryAmmoType };
	info.m_pAttacker = pPlayer;

	-- Fire the bullets, and force the first shot to be perfectly accuracy
	pPlayer:FireBullets( info );

	--Disorient the player
	local angles = pPlayer:GetLocalAngles();

	angles.x = angles.x + random.RandomInt( 0 );
	angles.y = angles.y + random.RandomInt( 0 );
	angles.z = 0;

if not _CLIENT then
	pPlayer:SnapEyeAngles( angles );
end

	pPlayer:ViewPunch( QAngle( -2, random.RandomFloat( -1, 0.3 ), 0 ) );

	if ( self.m_iClip1 == 0 and pPlayer:GetAmmoCount( self.m_iPrimaryAmmoType ) <= 0 ) then
		-- HEV suit - indicate out of ammo condition
		pPlayer:SetSuitUpdate( "!HEV_AMO0", 0, 0 );
	end
end

function SWEP:SecondaryAttack()
local pPlayer = self:GetOwner();
	if ( ToBaseEntity( pPlayer ) == NULL ) then
		return;
	end

  self:WeaponSound( 1 );

	self:SendWeaponAnim( 63 );
	pPlayer:SetAnimation( 5 );
	ToHL2MPPlayer(pPlayer):DoAnimationEvent( 0 );

  local vecSrc		= pPlayer:Weapon_ShootPosition();
	local vecAiming		= pPlayer:GetAutoaimVector( 0.08715574274766 );

	local info = { m_iShots = 1, m_vecSrc = vecSrc, m_vecDirShooting = vecAiming, m_vecSpread = vec3_origin, m_flDistance = 60, m_iAmmoType = self.m_iPrimaryAmmoType };
	info.m_pAttacker = pPlayer;
end

function SWEP:Reload()
end

function SWEP:Think()
end

function SWEP:CanHolster()
end

function SWEP:Deploy()
end

function SWEP:GetDrawActivity()
	return 171;
end

function SWEP:Holster( pSwitchingTo )
end

function SWEP:ItemPostFrame()
end

function SWEP:ItemBusyFrame()
end

function SWEP:DoImpactEffect()
end
