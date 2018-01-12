#pragma once

namespace LiteCppDB
{
	// Implement a locker service locking datafile to shared/reserved and exclusive access mode
	// Implement both thread lock and process lock
	// Shared -> Reserved -> Exclusive => !Reserved => !Shared
	// Reserved -> Exclusive => !Reserved
	// [Thread Safe]
	class LockService
	{
//#pragma region Properties + Ctor
//	private:
//
//		TimeSpan _timeout;
//		IDiskService _disk;
//		CacheService _cache;
//		Logger _log;
//		LockState _state;
//		bool _shared = false;
//		ReaderWriterLockSlim _thread = new ReaderWriterLockSlim(LockRecursionPolicy.NoRecursion);
//
//		LockService(IDiskService disk, CacheService cache, TimeSpan timeout, Logger log);
//
//	public:
//		// Get current datafile lock state
//		LockState getState{ return _state; };
//
//#pragma endregion
//
//#pragma region Public Methods
//
//		// Enter in Shared lock mode.
//		LockControl Shared();
//
//		// Enter in Reserved lock mode.
//		LockControl Reserved();
//
//		// Enter in Exclusive lock mode
//		LockControl Exclusive();
//
//#pragma endregion
//
//#pragma region Process lock control
//
//		// Try enter in shared lock (read) - Call action if request a new lock
//		// [Non ThreadSafe]
//		Action LockShared();
//
//	private:
//		// Try enter in reserved mode (read - single reserved)
//		// [ThreadSafe] (always inside an Write())
//		Action LockReserved();
//
//		// Try enter in exclusive mode (single write)
//		// [ThreadSafe] - always inside Reserved() -> Write() 
//		Action LockExclusive();
//
//#pragma endregion
//
//#pragma region Thread lock control
//
//		// Start new shared read lock control using timeout
//		Action ThreadRead();
//
//		// Start new exclusive write lock control using timeout
//		Action ThreadWrite();
//
//#pragma endregion
//
//		// Test if cache still valid (if datafile was changed by another process reset cache)
//		// [Thread Safe]
//		void AvoidDirtyRead();
	};
}