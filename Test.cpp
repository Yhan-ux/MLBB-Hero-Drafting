//#include <gtest/gtest.h>
//#include "HeroFactory.h"
//#include "Team.h"
//
//TEST(HeroFactoryTest, CreateValidHeroMage) {
//    Hero* hero = HeroFactory::createHero("Mage", "Lylia");
//    ASSERT_NE(hero, nullptr);
//    EXPECT_EQ(hero->getRole(), "Mage");
//    EXPECT_EQ(hero->getName(), "Lylia");
//    delete hero;
//}
//
//TEST(HeroFactoryTest, CreateValidHeroTank) {
//    Hero* hero = HeroFactory::createHero("Tank", "Tigreal");
//    ASSERT_NE(hero, nullptr);
//    EXPECT_EQ(hero->getRole(), "Tank");
//    EXPECT_EQ(hero->getName(), "Tigreal");
//    delete hero;
//}
//
//TEST(HeroFactoryTest, CreateValidHeroMarksman) {
//    Hero* hero = HeroFactory::createHero("Marksman", "Layla");
//    ASSERT_NE(hero, nullptr);
//    EXPECT_EQ(hero->getRole(), "Marksman");
//    EXPECT_EQ(hero->getName(), "Layla");
//    delete hero;
//}
//
//TEST(HeroFactoryTest, CreateValidHeroAssassin) {
//    Hero* hero = HeroFactory::createHero("Assassin", "Gusion");
//    ASSERT_NE(hero, nullptr);
//    EXPECT_EQ(hero->getRole(), "Assassin");
//    EXPECT_EQ(hero->getName(), "Gusion");
//    delete hero;
//}
//
//TEST(HeroFactoryTest, CreateValidHeroSupport) {
//    Hero* hero = HeroFactory::createHero("Support", "Estes");
//    ASSERT_NE(hero, nullptr);
//    EXPECT_EQ(hero->getRole(), "Support");
//    EXPECT_EQ(hero->getName(), "Estes");
//    delete hero;
//}
//
//TEST(HeroFactoryTest, CreateValidHeroFighter) {
//    Hero* hero = HeroFactory::createHero("Fighter", "Chou");
//    ASSERT_NE(hero, nullptr);
//    EXPECT_EQ(hero->getRole(), "Fighter");
//    EXPECT_EQ(hero->getName(), "Chou");
//    delete hero;
//}
//
//TEST(HeroFactoryTest, CreateInvalidHero) {
//    Hero* hero = HeroFactory::createHero("Alien", "Zorg");
//    EXPECT_EQ(hero, nullptr);
//}
//
//TEST(HeroPoolTest, PoolContainsExpectedHeroes) {
//    const auto& pool = HeroFactory::getHeroPool();
//    EXPECT_GE(pool.at("Tank").size(), 5);
//    EXPECT_GE(pool.at("Mage").size(), 5);
//    EXPECT_GE(pool.at("Marksman").size(), 5);
//    EXPECT_GE(pool.at("Assassin").size(), 5);
//    EXPECT_GE(pool.at("Support").size(), 5);
//    EXPECT_GE(pool.at("Fighter").size(), 5);
//}
//
//TEST(TeamTest, AssignAndDisplayHero) {
//    Team team;
//    Hero* hero = HeroFactory::createHero("Fighter", "Chou");
//    ASSERT_NE(hero, nullptr);
//    team.assignHeroToPosition("EXP", hero);
//
//    testing::internal::CaptureStdout();
//    team.displayTeam();
//    std::string output = testing::internal::GetCapturedStdout();
//
//    EXPECT_NE(output.find("Chou"), std::string::npos);
//    EXPECT_NE(output.find("[Fighter]"), std::string::npos);
//    delete hero;
//}
//
//TEST(TeamTest, MultipleAssignments) {
//    Team team;
//    Hero* hero1 = HeroFactory::createHero("Tank", "Atlas");
//    Hero* hero2 = HeroFactory::createHero("Mage", "Lunox");
//    Hero* hero3 = HeroFactory::createHero("Marksman", "Beatrix");
//
//    team.assignHeroToPosition("Roam", hero1);
//    team.assignHeroToPosition("Mid", hero2);
//    team.assignHeroToPosition("Gold", hero3);
//
//    testing::internal::CaptureStdout();
//    team.displayTeam();
//    std::string output = testing::internal::GetCapturedStdout();
//
//    EXPECT_NE(output.find("Atlas"), std::string::npos);
//    EXPECT_NE(output.find("Lunox"), std::string::npos);
//    EXPECT_NE(output.find("Beatrix"), std::string::npos);
//
//    delete hero1;
//    delete hero2;
//    delete hero3;
//}
//
//int main(int argc, char **argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
