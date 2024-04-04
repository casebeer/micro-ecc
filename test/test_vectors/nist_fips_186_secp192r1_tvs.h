#include "test_vector.h"
Test nist_fips_186_secp192r1_tvs[] = {
    {
      /* test vector 0 for P-192 */
      "0017899949d02b55f9556846411cc9de512c6f16ecdeb1c4", /* private_key */
      "14f69738599689f5706ab71343becc886ef1569a2d1137fe0cf5a433909e33217fb4df6b9593f71d43fb1c2a5653b763", /* public_key */
      "0098e9c07e8e6adb97b77d85b0c10a265e11737a89a3e37b", /* k */
      "5c8190e87adb631bb5537f3f5f478888bd002ff5", /* SHA1 hash */
      "af1f749e3df6220ff04efd178618a977e0838b1b9dc126e3", /* R */
      "8990a04c6cc0ff26264ecf8f7831381a9dbc6e53cc8cc860", /* S */
    },
    {
      /* test vector 1 for P-192 */
      "0064c3a51fb6188170f3cdf12b474a77de4ae0052b84ece8", /* private_key */
      "386afa71afc065019f3d2021ead531ed1d365887122d2d4bbbfb6e9cdb32c2252015acfb4cfb049b08b4cb279c64928a", /* public_key */
      "00797552b9abf541c886f93556103b817a46c9aa0e2bc86f", /* k */
      "005e97fa0177ffff868cdac356508e22cbe730d2", /* SHA1 hash */
      "337be42eebdcedd97678eeaae9d1b231b740a191a293c22a", /* R */
      "9d6766b391e95f649e05442453a85466da29eaa97ddcfc62", /* S */
    },
    {
      /* test vector 2 for P-192 */
      "00abd205ef412646907d2e4886b8ffd7d94678bd3818ed54", /* private_key */
      "3b1c19d73b6a4d7a12003530a54ae0f5ba18d75c98a0db95afb8bd8c94c6e3d5dc050e3641c0fad771557ce97f5f3dba", /* public_key */
      "00b81567f9e19c4ace373a26337488c1a476b7ee8d8e52bf", /* k */
      "619c5a0cea316912adbf92a8212bad2187453bc6", /* SHA1 hash */
      "e36d5dbb9560d959814cbd30aa6a405da9652fbd250da9ab", /* R */
      "f2db3d62733f6d08b08ef0682f579ac527950117f39e474b", /* S */
    },
    {
      /* test vector 3 for P-192 */
      "0045624e643545c113e4a1993cfac6f23c6e0486c98e14c9", /* private_key */
      "21933e6e8cdcfff62f36c45e83dece1280a888663a34608f565890e37fdf563595d24524ef1da9aae246892e75a74234", /* public_key */
      "008df8209daae53a365bdcc8608f597315d43f587859d96a", /* k */
      "179a36aa602e23665295d895581fe44b138da3dc", /* SHA1 hash */
      "1791e503645e53a8304f2a44715942c6aab315b0086f4147", /* R */
      "366309b7f79b2fd98d6c2f3a8424178b01235041f9869552", /* S */
    },
    {
      /* test vector 4 for P-192 */
      "00ca3e5b5d69cf028c9ff138b1ee5c28607a6bf9352c6430", /* private_key */
      "4828ad4aff5d87dcca98a341344a462edf277850755c72778a1bfc6b7b0424e15454ac198d4d697927f4eaaf9d14d88e", /* public_key */
      "00964e4a3eac4d2641c2a5c4badd301da54962410a459654", /* k */
      "a35b163e77befe4fc68f61c328e309f41b196004", /* SHA1 hash */
      "c438ca66c5d3b19e2bcd26a5c54742435f25ee0e9364b41c", /* R */
      "ff194479695afdcc88645f2a309cb99717beac26794c0658", /* S */
    },
    {
      /* test vector 5 for P-192 */
      "0055ace67df2b17f6e9e1b8928ac856ce8d75f6bbaaaed83", /* private_key */
      "2f5d05cbd620145b41d0a1c656d676ead2fc651b3cf71cc288d2386cfb812d02a1fa19578a7cd04b356920a2b2e69839", /* public_key */
      "006ed729e5c2ec9bac7ddfbfe04ea9444c2c77f71455f623", /* k */
      "e6890e6692407724d039d4a8d4f957d5554b30fb", /* SHA1 hash */
      "cde95d12d650102c535fdc1994fc468308b05e2af7af9c14", /* R */
      "c2606a54e7592214a265270918322ae33d487268b9108cae", /* S */
    },
    {
      /* test vector 6 for P-192 */
      "00d185d51f877d3fcc657d18f30cd14570022d0726c0b188", /* private_key */
      "47e8ec5e1edb1d23c04ebfeefd8cb8bf39cd48c348de3ea7b1167b3a4e2fbe167bbd7b7b06bf1314d58d9e3976ffa47f", /* public_key */
      "00124c96b0dd589501ba7d5ddfe9c412cf574be10198899b", /* k */
      "8b7bc5a5967111272dc68ca86e3b72b9a493b8d3", /* SHA1 hash */
      "539e285389399c785dfc4f3bfccbc825602f443ae0dca3d1", /* R */
      "ed56e54fbaa0b7c0bc462920314031c7a3e7b2eb701cb9db", /* S */
    },
    {
      /* test vector 7 for P-192 */
      "007d6fa0b3dacaf022436777ac53c4437c957947c911faab", /* private_key */
      "a4db1303bf13696e26678286e27c166dd87be98cc8be284409b4de84bbfa77e049ace272a12d0dd141d363e74ec12511", /* public_key */
      "00620f584b08d3199f6841fefa4b920659b267271c9b4034", /* k */
      "3387cd04272f60f84bf82f27b154324da4abf6ed", /* SHA1 hash */
      "6818d44aea421701e3f41600c867fb3d3749eadbf33820fa", /* R */
      "658b228b2edd8569f6940fee1c303626e48181094581987b", /* S */
    },
    {
      /* test vector 8 for P-192 */
      "00b5bfd09a8d177513c4bd7d1bd9ac5ccb7c00c63b9841b4", /* private_key */
      "270d7bb9bfab54529240426a08508f1ed90dc7914cdf11f3c91ed7f2eca39f563757c5b518d9c28d4d41e7bdc0c7f53e", /* public_key */
      "00dbc3fbf7b320e9bb6bae128ae19f2c67b297ceb9bc697f", /* k */
      "19c4f2d298c703b56791b3454a2eacb93088b6e0", /* SHA1 hash */
      "db20f09b69ac79e224258800ebe6cc51a2e12536b69396c8", /* R */
      "d31df9544277f4a79676fdc7a51faef73ee2a0d1057ff3a2", /* S */
    },
    {
      /* test vector 9 for P-192 */
      "00958e4bbbdd8709a78441485d6f57dee96cc4d98c38ad4f", /* private_key */
      "6a5723e72f6270160f256ddd403c108503388d4320f7926cf52b0e0e4c8871443cfc0c231e856f6adc2a7c3318a43578", /* public_key */
      "0045f392d1910760550b34e64d578905c20fb1cc51b29eef", /* k */
      "b552b660da681cb93d739f21c57ef1bf84926f5d", /* SHA1 hash */
      "6505663a952b741c4583e755496740833d5901fc09433963", /* R */
      "de0411972e27bfb80362b44650e687866cd202a4199d605c", /* S */
    },
    {
      /* test vector 10 for P-192 */
      "004960533b788b3fad017e610f5ddab750b4bf5a5e9d0964", /* private_key */
      "1c0e4fc6d8f4e7605f2bf57541395f5167d41d8bdd5c4f80775da73226020bad6ec4df5022a8c61aee064372ba535ae7", /* public_key */
      "00e93a10b115218fcb2f0413784385e1fc4555b1818f3b3c", /* k */
      "b2e39a27756979bd647879a4f22008b2624f8f8d", /* SHA1 hash */
      "bc540a8f5ea81c6144698f5452556f17da76a52636461d70", /* R */
      "2de23f6cc9a45899a9f605dab9f28fddf9e376ea06c92db5", /* S */
    },
    {
      /* test vector 11 for P-192 */
      "00cf08df71e8343af55fc20ca9d6ae822f9bbdf5ab7d2113", /* private_key */
      "194e8fdd4b6b84f1955d1919387f96facf6feadd8105d8dd2eb47a2ed3aac4250be37f9e31d7ff87be4043ac1eac401f", /* public_key */
      "009758de92827113c0d1ece5ad9ab65d9acf18f74b58ecf6", /* k */
      "81b29a3019476a387455b61fffd83ac83ffcd8d0", /* SHA1 hash */
      "0bbd331b5cbcaef2b26e27bdc559d31c62d5c9b6b8979603", /* R */
      "c1670a3b435805fa7ab20e6dd8ffa1012e9fb41b1d7d0176", /* S */
    },
    {
      /* test vector 12 for P-192 */
      "0027492bdd573a53baafd1575578fdce242e43f2e3537a0b", /* private_key */
      "18b94fc7825bad91b1ca5a69cdf576377ad76965670d39670a73253d6df54d5105f0ca2f948d0686706dbd064744f7c3", /* public_key */
      "00d8966cd03fdb2509193ddeee3b429cab2605e283c98577", /* k */
      "e062ee7eb959f9c7f33828b71c04a846b3dfac22", /* SHA1 hash */
      "1a813b607c0b4d71e7acdac040eb78b3795e53bc498bae85", /* R */
      "67fc1124c30966473dc6a1f14ae32ec2dd860b3667c61dec", /* S */
    },
    {
      /* test vector 13 for P-192 */
      "00066eb1a5e6a42b53fcc82fcf6a601d023127c7b1c779db", /* private_key */
      "3888a94ef288ebe32b4b9b53bf2d3a85b45976583251f0ec30156d8e0d212a66c071fb2e7b422ef1784a95dacffd9edb", /* public_key */
      "008c135723cb6a10cbd3e2cde313aee847477e66c4220f47", /* k */
      "8d30f57068ecc59b8a3a3897a51cc1cf19b674fe", /* SHA1 hash */
      "37033150afed029fd8390716eac6500223e72154ccff9fee", /* R */
      "b4e978e8d499cc1be576dea74c0dd74cafe9e794a7563172", /* S */
    },
    {
      /* test vector 14 for P-192 */
      "006dfc40880e0c42d2cebcdee255040d18bb99190981f9a9", /* private_key */
      "b11956a29af6984043973e2de46d53d870e04687cae59728c915f88aa0fa9822762cc4e60df759d189a10c486b901d5e", /* public_key */
      "009e03961f041fa811ff88c4948bc0a6d867a7fef5f39453", /* k */
      "8778cce9e8ad6541b9710e3f7067bc2c9cbc6541", /* SHA1 hash */
      "c459f7bcea050210e3369ac174ba89c823ca1b0d4c0964f6", /* R */
      "04715cba9ba31c4ed9bf0be07d194e2a709294472cc60bdf", /* S */
    },
};
