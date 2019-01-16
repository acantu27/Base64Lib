#include "Base64.h"
#include <gtest/gtest.h>

TEST(Base64, Encode) {
    Base64::Base64 encodeObj;
    EXPECT_EQ("YQ==", encodeObj.encode64("a"));
    EXPECT_EQ("aGc=", encodeObj.encode64("hg"));
    EXPECT_EQ("ZDRm", encodeObj.encode64("d4f"));
    EXPECT_EQ("ZDQ1M2Rmc2Rmc2Q=", encodeObj.encode64("d453dfsdfsd"));
    EXPECT_EQ("NjdnZGZmZ2ZkczMzM2Zlc2Rmcw==", encodeObj.encode64("67gdffgfds333fesdfs"));
    EXPECT_EQ("aGV5d2hhdHNnb2luZ29uZmVsbGFz", encodeObj.encode64("heywhatsgoingonfellas"));
    EXPECT_EQ("Y2hpY2tlbmlzaGVyZXNhbGV3aXRod2hhbGVzYW5kY29ybm51Z2dldHNmb3JhbGx0aW1leWF5",
              encodeObj.encode64("chickenisheresalewithwhalesandcornnuggetsforalltimeyay"));
}

TEST(Base64, Decode) {
    Base64::Base64 decodeObj;
    EXPECT_EQ("t", decodeObj.decode64("dA=="));
    EXPECT_EQ("p0", decodeObj.decode64("cDA="));
    EXPECT_EQ("2wG", decodeObj.decode64("MndH"));
    EXPECT_EQ("jD7hks3jjjsflL", decodeObj.decode64("akQ3aGtzM2pqanNmbEw="));
    EXPECT_EQ("8u7Ng6POmT3saaaa", decodeObj.decode64("OHU3Tmc2UE9tVDNzYWFhYQ=="));
    EXPECT_EQ("JKL9HJDH2jkjjkjk123", decodeObj.decode64("SktMOUhKREgyamtqamtqazEyMw=="));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}