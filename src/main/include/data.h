namespace CasGD {
	template <typename type>
	class DataItem {
		private:
			type* pointer = 0;

		public:
			DataItem(type* poiner);
			DataItem(long addrs);

			type* getPoiner();
	};
}